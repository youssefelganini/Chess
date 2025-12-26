#include"move.h"
#include<math.h>
#include<stdio.h>
#include"board.h"
#include<stdlib.h>
#include"game.h"


/*
1-checkmate
2-stalmate{2loops(King vs King),(ing + Bishop vs King),(King + Knight vs King),(King + Bishop + Bishop (both same color) vs King)} donne
3-report
*/




/*----------------------------------------------HELPER FN------------------------------------------------*/
int input_as_int[4];
void convert_input_to_int(char *x){
    input_as_int[0] = x[0] - 'a';        // column a-h -> 0-7
    input_as_int[1] = 8 - (x[1] - '0');  // rank 1-8 -> row 7-0
    input_as_int[2] = x[2] - 'a';
    input_as_int[3] = 8 - (x[3] - '0');
}
int sign(int x){ /*to know the piece go forward or backward*/
    if(x>0) return 1;
    if(x<0) return -1;
    return 0;
}
/*----------------------------------------------MOVES LOGIC------------------------------------------------*/
int rook(int from_row,int from_col,int to_row,int to_col){ /*input=[a,3,a,4]*/
    if(from_col==to_col&&from_row!=to_row) return 1;
    if(from_col!=to_col&&from_row==to_row) return 1;
    return 0;
}

int king(Board *board, Game *game, int from_row,int from_col,int to_row,int to_col){
int enrow;
int encol;
if(game->current_player==WHITE){
    enrow=board->bkingsq[0];
    encol=board->bkingsq[1];
}
else{
    enrow=board->wkingsq[0];
    encol=board->wkingsq[1];
}
if(abs(from_col-to_col)<=1 &&
    abs(from_row-to_row)<=1 &&
    (abs(to_row-enrow)>1||abs(to_col-encol)>1))
    return 1;
return 0;
}

int bishop(int from_row,int from_col,int to_row,int to_col){
    if(abs(to_col-from_col)==abs(to_row-from_row)) return 1;
    return 0;
}


int knight(int from_row,int from_col,int to_row,int to_col){
if(((abs(from_col-to_col)==2) && (abs(from_row-to_row)==1)) || 
   ((abs(from_col-to_col)==1) && (abs(from_row-to_row)==2))) return 1;
   return 0;
}
int queen(int from_row,int from_col,int to_row,int to_col){
    if(rook(from_row,from_col,to_row,to_col)||bishop(from_row,from_col,to_row,to_col)) return 1;
    return 0;
}
/*----------------------------------------------PATH------------------------------------------------*/
int path_check(Board *board,int from_row,int from_col,int to_row,int to_col){
    int dx=sign(to_col-from_col);
    int dy=sign(to_row-from_row);
    int x=dx+from_col;
    int y=dy+from_row;
    while (x!=to_col||y!=to_row)
    {
        if(board->square[y][x].type!= EMPTY) return 0;
        x+=dx;
        y+=dy;
    }
    return 1;
}
int dest_check(Board *board,int from_row,int from_col,int to_row,int to_col){
    if(board->square[to_row][to_col].color==board->square[from_row][from_col].color ) return 0;
    return 1;
}
/*----------------------------------------------CASTLING------------------------------------------------*/
int castling_path_clear(Board *board,int king_row,int king_col,int rook_col) {
    int dx;
    if((rook_col-king_col)>0){ 
        dx=1;
    }  
    else dx=-1;
    int x=king_col + dx;

    while (x!= rook_col) {  
        if (board->square[king_row][x].type!=EMPTY) {
            return 0; 
        }
        x += dx;
    }
    return 1; 
}
int castling(Board *tempboard,char *castl,Game *game,Board *board){
    convert_input_to_int(castl);
    char piece=piece_char(board->square[input_as_int[1]][input_as_int[0]]);
    execute_move(tempboard,input_as_int[1],input_as_int[0],input_as_int[3],input_as_int[2]);
    if(is_king_checked(tempboard,game)) {
        printf("YOUR KING WILL BE CHECKED!");
        return 0;} 
    if(game->current_player==WHITE){
        if(piece!='K') return 0;
        if(input_as_int[2]==6&&input_as_int[3]==7){
            if(board->whitekingmoved==1||board->whiterook_hmoved==1){
                printf("You cannot castle, king or rook has moved\n");
                return 0;
            }
            if(board->square[7][4].type!=KING||board->square[7][7].type!=ROOK) return 0;
            if(!castling_path_clear(board,7,4,7)){
                printf("Cannot castle, path blocked\n");
                return 0;
            }
            if(game->flag==1){
                printf("You cannot castle while your king is in check\n");
                return 0;
            }
            execute_move(board,7,4,7,6);
            execute_move(board,7,7,7,5);
            return 1;
        } else if(input_as_int[2]==2&&input_as_int[3]==7){
            if(board->whitekingmoved==1||board->whiterook_amoved==1){
                printf("You cannot castle, king or rook has moved\n");
                return 0;
            }
            if(board->square[7][4].type!=KING||board->square[7][0].type!=ROOK) return 0;
            if(!castling_path_clear(board,7,4,0)){
                printf("Cannot castle, path blocked\n");
                return 0;
            }
            if(game->flag==1){
                printf("You cannot castle while your king is in check\n");
                return 0;
            }
            execute_move(board,7,4,7,2);
            execute_move(board,7,0,7,3);
            return 1;
        } else {
            return 0;
        }
    } else if(game->current_player==BLACK){
        if(piece!='k') return 0;
        if(input_as_int[2]==6&&input_as_int[3]==0){
            if(board->blackkingmoved==1||board->blackrook_hmoved==1){
                printf("You cannot castle, king or rook has moved\n");
                return 0;
            }
            if(board->square[0][4].type!=KING||board->square[0][7].type!=ROOK) return 0;
            if(!castling_path_clear(board,0,4,7)){
                printf("Cannot castle, path blocked\n");
                return 0;
            }
            if(game->flag==1){
                printf("You cannot castle while your king is in check\n");
                return 0;
            }
            execute_move(board,0,4,0,6);
            execute_move(board,0,7,0,5);
            return 1;
        } else if(input_as_int[2]==2&&input_as_int[3]==0){
            if(board->blackkingmoved==1||board->blackrook_amoved==1){
                printf("You cannot castle, king or rook has moved\n");
                return 0;
            }
            if(board->square[0][4].type!=KING||board->square[0][0].type!=ROOK) return 0;
            if(!castling_path_clear(board,0,4,0)){
                printf("Cannot castle, path blocked\n");
                return 0;
            }
            if(game->flag==1){
                printf("You cannot castle while your king is in check\n");
                return 0;
            }
            execute_move(board,0,4,0,2);
            execute_move(board,0,0,0,3);
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}



/*----------------------------------------------PROMATION------------------------------------------------*/
int pawn_promotion(Board *board){
    if(board->square[input_as_int[3]][input_as_int[2]].type==PAWN &&
       board->square[input_as_int[3]][input_as_int[2]].color==WHITE&&input_as_int[3]==0){
        return 1;
    }
    if(board->square[input_as_int[3]][input_as_int[2]].type==PAWN &&
       board->square[input_as_int[3]][input_as_int[2]].color==BLACK&&input_as_int[3]==7){
        return 1;
    }
    return 0;
}
int change_pawn(Board *board, Move *move){
    if(pawn_promotion(board)){
        char promotion;
        printf("Enter which piece you want\n");
        scanf(" %c",&promotion);
        switch(promotion){
            case 'Q':
            case 'q': board->square[input_as_int[3]][input_as_int[2]].type=QUEEN;break;
            case 'R':
            case 'r': board->square[input_as_int[3]][input_as_int[2]].type=ROOK; break;
            case 'B':
            case 'b': board->square[input_as_int[3]][input_as_int[2]].type=BISHOP; break;
            case 'N':
            case 'n': board->square[input_as_int[3]][input_as_int[2]].type=KNIGHT; break;
            default: 
                printf("Invalid input\n");
                return 0;
        }
        move->history[move->move_count - 1].promoted_piece = board->square[input_as_int[3]][input_as_int[2]];
        return 1;
    }
    return 0;
}
/*----------------------------------------------En passant------------------------------------------------*/
int enpasswn(Board *board, int from_row, int from_col,int to_row, int to_col){
    Piece moving_piece = board->square[from_row][from_col];
    if(moving_piece.type == PAWN && to_row == board->enpassen_row && to_col == board->enpassen_col){
        if(moving_piece.color == WHITE) {
            board->blackcaptured[board->blackcapturedcount++] = board->square[board->enpassen_row + 1][board->enpassen_col];
            board->square[board->enpassen_row + 1][board->enpassen_col].type = EMPTY;
            board->square[board->enpassen_row + 1][board->enpassen_col].color = EMPTY;
        } else if(moving_piece.color == BLACK) {
            board->whitecaptured[board->whitecapturedcount++] = board->square[board->enpassen_row - 1][board->enpassen_col];
            board->square[board->enpassen_row - 1][board->enpassen_col].type = EMPTY;
            board->square[board->enpassen_row - 1][board->enpassen_col].color = EMPTY;
        }
    }

    int des=input_as_int[3]-input_as_int[1];
    int dx=sign(des);
    if(board->square[input_as_int[1]][input_as_int[0]].type!=PAWN) {
        board->enpassen_row=-1;
        board->enpassen_col=-1;
        return 0;}
    if(abs(des)!=2) {
        board->enpassen_row=-1;
        board->enpassen_col=-1;
        return 0;}
    board->enpassen_row=input_as_int[1]+dx;
    board->enpassen_col=input_as_int[0];
    return 1;
}
/*----------------------------------------------KING CHECK------------------------------------------------*/
int can_attack(Board *board,int from_row,int from_col,int to_row,int to_col){
    int attaker=board->square[from_row][from_col].type;
    switch (attaker)
    {
    case ROOK:
        if(rook(from_row,from_col,to_row,to_col)){
            if(path_check(board,from_row,from_col,to_row,to_col)){
                return 1;
            }
        }
        return 0;
    case BISHOP:
        if(bishop(from_row,from_col,to_row,to_col)){
            if(path_check(board,from_row,from_col,to_row,to_col)){
                return 1;
            }
        }
        return 0;
    case KNIGHT:
        if(knight(from_row,from_col,to_row,to_col)) return 1;
        return 0;
    case QUEEN:
        if(queen(from_row,from_col,to_row,to_col)){
            if(path_check(board,from_row,from_col,to_row,to_col)){
                return 1;
            }
        }
        return 0;
    case PAWN:
        if(board->square[from_row][from_col].color==BLACK){
            if(from_row==to_row+1&&( from_col==to_col+1||from_col==to_col-1)){
                return 1;
            }
        }
        if(board->square[from_row][from_col].color==WHITE){
            if(from_row==to_row-1&&(from_col==to_col+1||from_col==to_col-1)){
                return 1;
            }
        }
        return 0;
        
    default:
        return 0;
    }

}


int is_king_checked(Board *board,Game *game){
    board->ktempb[0]=board->bkingsq[0];
    board->ktempb[1]=board->bkingsq[1];
    board->ktempw[0]=board->wkingsq[0];
    board->ktempw[1]=board->wkingsq[1];
    if(game->current_player==WHITE){
        for(int i=0; i<8;i++){
            for(int j=0;j<8;j++){
                if(board->square[i][j].color==BLACK){
                    if(can_attack(board,i,j,board->wkingsq[0],board->wkingsq[1]))return 1;
                }
            }
        }
        return 0;
    }
    if(game->current_player==BLACK){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board->square[i][j].color==WHITE){
                    if(can_attack(board,i,j,board->bkingsq[0],board->bkingsq[1])) return 1;
                }
            }
        }
        return 0;
    }
    return 0;    
}
/*----------------------------------------------CHECKMATE------------------------------------------------*/
int no_king_can_move(Board *board,Move *move,Game *game){
    int row_king;
    int col_king;
    if(game->current_player==WHITE){
        row_king=board->wkingsq[0];
        col_king=board->wkingsq[1];
    }
    else{
         row_king=board->bkingsq[0];
         col_king=board->bkingsq[1];
    }
    if(is_king_checked(board, game)==0) return 0;
    int dy[]={-1,-1,-1, 0, 0, 1, 1, 1};
    int dx[]={-1, 0, 1,-1, 1,-1, 0, 1};
    
    for(int i = 0; i < 8; i++){
        if(game->current_player==WHITE){
            int new_row=row_king+dy[i];
            int new_col=col_king+dx[i];
            if(new_row<0 || new_row>7 || new_col<0 || new_col>7) {
                continue;
            }

            if (board->square[new_row][new_col].color == game->current_player) {
                continue;
            }
            if(king(board, game, board->wkingsq[0],board->wkingsq[1],new_row,new_col)==0) continue;
            Board tempboard = *board;
            Move tempmove = *move;
            tempmove.from_row = row_king;
            tempmove.from_col = col_king;
            tempmove.to_row = new_row;
            tempmove.to_col = new_col;
            tempmove.moved_piece = board->square[row_king][col_king];
            tempmove.captured_piece = board->square[new_row][new_col];
            execute_move(&tempboard,row_king,col_king,new_row,new_col);
            int still_checked=is_king_checked(&tempboard, game);
            reverse_move(&tempboard, tempmove.from_row, tempmove.from_col, tempmove.to_row, tempmove.to_col, tempmove.moved_piece, tempmove.captured_piece);

            if(still_checked==0) {
                return 0;
            }
        }
        else if(game->current_player==BLACK){
            int new_row=row_king+dy[i];
            int new_col=col_king+dx[i];
            if(new_row<0 || new_row>7 || new_col<0 || new_col>7) {
                continue;
            }

            if (board->square[new_row][new_col].color == game->current_player) {
                continue;
            }
            if(king(board, game, board->bkingsq[0],board->bkingsq[1],new_row,new_col)==0) continue;
            Board tempboard = *board;
            Move tempmove = *move;
            tempmove.from_row = row_king;
            tempmove.from_col = col_king;
            tempmove.to_row = new_row;
            tempmove.to_col = new_col;
            tempmove.moved_piece = board->square[row_king][col_king];
            tempmove.captured_piece = board->square[new_row][new_col];
            execute_move(&tempboard,row_king,col_king,new_row,new_col);
            int still_checked=is_king_checked(&tempboard, game);
            reverse_move(&tempboard, tempmove.from_row, tempmove.from_col, tempmove.to_row, tempmove.to_col, tempmove.moved_piece, tempmove.captured_piece);

            if(still_checked==0) {
                return 0;
            }
        }
    }
    return 1;
}
int no_check_blocked_orCaptured(Board *board, Move *move, Game *game){
    if(is_king_checked(board,game)==0) return 0;
    Board temp= *board;
    Move tempmove = *move;

    int color=game->current_player;
    for(int from_row=0;from_row<8;from_row++){
        for(int from_col=0;from_col<8;from_col++){
            if(board->square[from_row][from_col].color!=color) continue;
            if(board->square[from_row][from_col].type==KING) continue;
            
            for(int to_row=0;to_row<8;to_row++){
                for(int to_col=0;to_col<8;to_col++){
                    if(validation(board,game,from_row,from_col,to_row,to_col)==0) continue;
                    tempmove.from_row = from_row;
                    tempmove.from_col = from_col;
                    tempmove.to_row = to_row;
                    tempmove.to_col = to_col;
                    tempmove.moved_piece = board->square[from_row][from_col];
                    tempmove.captured_piece = board->square[to_row][to_col];
                    execute_move(&temp,from_row,from_col,to_row,to_col);
                    if(is_king_checked(&temp,game)==0) return 0;
                    reverse_move(&temp, tempmove.from_row, tempmove.from_col, tempmove.to_row, tempmove.to_col, tempmove.moved_piece, tempmove.captured_piece);
                }
            }
        }
    }
    return 1;
}

int chekmate(Board *board,Move *move,Game *game){
    if(is_king_checked(board,game)==0) return 0;
    if(no_check_blocked_orCaptured(board,move,game)&&no_king_can_move(board,move,game)) return 1;
    return 0;
}
/*----------------------------------------------STALMATE&DRAW------------------------------------------------*/
int stalmate(Board *board,Game *game){
    if(is_king_checked(board,game)) return 0; 
    int color=game->current_player;
    for(int from_row=0;from_row<8;from_row++){
        for(int from_col=0;from_col<8;from_col++){
            if(board->square[from_row][from_col].color!=color) continue;
            for(int to_row=0;to_row<8;to_row++){
                for(int to_col=0;to_col<8;to_col++){
                    if(validation(board,game,from_row,from_col,to_row,to_col)){
                        execute_move(board,from_row,from_col,to_col,to_col);
                        if(is_king_checked(board,game)==0) return 0;

                    }
                }
            }
        }
    }

    return 1;
}
int draw(Board *board,Game *game){
    /*something for bishop later*/
    if((is_king_checked(board,game)==1)) return 0;
    int knighes[2]={0};
    int bishop[2]={0};
    for(int from_row=0;from_row<8;from_row++){
        for(int from_col=0;from_col<8;from_col++){
            if(board->square[from_row][from_col].type==QUEEN||board->square[from_row][from_col].type==ROOK||board->square[from_row][from_col].type==PAWN) return 0;
            if(board->square[from_row][from_col].type==KNIGHT &&board->square[from_row][from_col].color==WHITE) knighes[0]++;
            if(board->square[from_row][from_col].type==KNIGHT &&board->square[from_row][from_col].color==BLACK) knighes[1]++;
            if(board->square[from_row][from_col].type==BISHOP &&board->square[from_row][from_col].color==BLACK) bishop[0]++;
            if(board->square[from_row][from_col].type==BISHOP &&board->square[from_row][from_col].color==BLACK) bishop[1]++;
            if(knighes[0]+bishop[0]>1||knighes[1]+bishop[1]>1) return 0;

        }
    }
    return 1;
}



/*----------------------------------------------VALIDATION------------------------------------------------*/
int validation(Board *board, Game *game,int from_row,int from_col,int to_row,int to_col){
    if(from_row<0 || from_row>7 || to_row<0 || to_row>7 || 
            from_row<0 || from_col>7 || to_col<0 || to_col>7) {
        return 0;
    }
    if(game->current_player==WHITE){
        if(board->square[from_row][from_col].color==BLACK){
            return 0;
        }
    }
    else if(game->current_player==BLACK){
        if(board->square[from_row][from_col].color==WHITE){
            return 0;
        }
    }
    if(board->square[from_row][from_col].type == EMPTY){
        return 0;
    }
    if(dest_check(board,from_row,from_col,to_row,to_col)==0){;
        return 0;
    }


    char piece=piece_char(board->square[from_row][from_col]); /*current piece*/
    if(from_col==to_col&&from_row==to_row) {
        return 0;}
    switch (piece)
    {
    case 'R':
    case 'r':
        if(path_check(board,from_row,from_col,to_row,to_col)==0){
            return 0;
        }
        return rook(from_row,from_col,to_row,to_col);
    case 'b':
    case 'B':
        if(path_check(board,from_row,from_col,to_row,to_col)==0){
            return 0;
        }
        return bishop(from_row,from_col,to_row,to_col);
    case 'q':
    case 'Q':
        if(path_check(board,from_row,from_col,to_row,to_col)==0){
            return 0;
        }
        return queen(from_row,from_col,to_row,to_col);
    case 'N':
    case 'n':
        return knight(from_row,from_col,to_row,to_col);
    case 'K':
    case 'k':
        return king(board, game, from_row,from_col,to_row,to_col);
    case 'P':
         if(from_row==6  && from_col==to_col ){
            if(to_row==4){
                 if(path_check(board,from_row,from_col,to_row,to_col)==0){
                    return 0;
                }
                if(board->square[to_row][to_col].type!= EMPTY) {
                    return 0;
                }     
            return 1;              
            }
        }
        if(to_row==from_row-1 &&from_col==to_col) {
           if(board->square[to_row][to_col].type!= EMPTY) {
                return 0;
            }/*check for pawn if there is piece a black piece or white where it goes*/
            else{
                return 1;
            }
        }
        if(from_row==3&&board->enpassen_col==to_col&&board->enpassen_row==to_row) return 1;
        if(to_row==from_row-1 &&(to_col==from_col+1||to_col==from_col-1)){
            if(board->square[to_row][to_col].color!=BLACK){
                return 0;
            }
            return 1;
        }
        return 0;
    case 'p':
        if(from_row==1 && from_col==to_col){
            if(to_row==3){
                if(path_check(board,from_row,from_col,to_row,to_col)==0){ 
                    return 0;
                }
                if(board->square[to_row][to_col].type!= EMPTY) {
                    return 0;
                }
                return 1;
            }
        }
        if(to_row==from_row+1 &&from_col==to_col) {
            if(board->square[to_row][to_col].type!= EMPTY) {
                return 0;
            }/*check for pawn if there is  a black piece or white where it goes*/
            else{
                return 1;
            }
        }
        if(from_row==4&&board->enpassen_col==to_col&&board->enpassen_row==to_row) return 1;
        if(to_row==from_row+1 &&(to_col==from_col+1||to_col==from_col-1)){
            if(board->square[to_row][to_col].color!=WHITE ){
                return 0;
            }
            return 1;
        }
        return 0;
        
    default:
        return 0;
    }

}
/*----------------------------------------------MOVE EXECUTE------------------------------------------------*/
void execute_move(Board *board, int from_row, int from_col,
                 int to_row, int to_col) {
    Piece moving_piece = board->square[from_row][from_col];
    Piece captured_piece = board->square[to_row][to_col];
    
 
    if (captured_piece.type != EMPTY) {
        if (captured_piece.color == BLACK) {
            board->blackcaptured[board->blackcapturedcount++] = captured_piece;
        } else {
            board->whitecaptured[board->whitecapturedcount++] = captured_piece;
        }
    }
    
    board->square[to_row][to_col] = moving_piece;
    board->square[from_row][from_col].type = EMPTY;
    board->square[from_row][from_col].color = EMPTY;

    if(moving_piece.type == KING) {
        if(moving_piece.color == WHITE) {
            board->whitekingmoved = 1;
            board->wkingsq[0] = to_row;
            board->wkingsq[1] = to_col;
        } else if(moving_piece.color == BLACK) {
            board->blackkingmoved = 1;
            board->bkingsq[0] = to_row;
            board->bkingsq[1] = to_col;
        }
    } else if(moving_piece.type == ROOK) {
        if(moving_piece.color == WHITE) {
            if(from_col == 0 && from_row == 7) {
                board->whiterook_amoved = 1;
            } else if(from_col == 7 && from_row == 7) {
                board->whiterook_hmoved = 1;
            }
        } else {
            if(from_col == 0 && from_row == 0) {
                board->blackrook_amoved = 1;
            } else if(from_col == 7 && from_row == 0) {
                board->blackrook_hmoved = 1;
            }
        }
    }
}



/*----------------------------------------------SAVE/REDO/UNDO/LOAD------------------------------------------------*/

void initialize_move_history(Move *move) {
    for (int i = 0; i < 100; i++) {
        move->history[i] = (MoveRecord){0};
        move->history[i].promoted_piece.type = EMPTY;
        move->history[i].promoted_piece.color = EMPTY;
    }
    move->move_count = 0;
    move->undo_count = 0;
}
void record_move(Move *move, int from_row, int from_col, int to_row, int to_col, Piece moved_piece, Piece captured_piece) {
    move->from_row = from_row;
    move->from_col = from_col;
    move->to_row = to_row;
    move->to_col = to_col;
    move->moved_piece = moved_piece;
    move->captured_piece = captured_piece;
    move->history[move->move_count].from_row = from_row;
    move->history[move->move_count].from_col = from_col;
    move->history[move->move_count].to_row = to_row;
    move->history[move->move_count].to_col = to_col;
    move->history[move->move_count].moved_piece = moved_piece;
    move->history[move->move_count].captured_piece = captured_piece;
    move->move_count++;
}
void reverse_move(Board *board, int from_row, int from_col, int to_row, int to_col, Piece moved_piece, Piece captured_piece) {
    // Restore the moved piece to its original position
    board->square[from_row][from_col] = moved_piece;  
    // Restore the captured piece (or empty) to the destination
    board->square[to_row][to_col] = captured_piece;
    // Reset movement flags if undoing a king or rook move (to allow castling again if applicable)
    if (moved_piece.type == KING) {
        if (moved_piece.color == WHITE) {
            board->whitekingmoved = 0;  // Reset flag
        } else if (moved_piece.color == BLACK) {
            board->blackkingmoved = 0;  // Reset flag
        }
    } else if (moved_piece.type == ROOK) {
        if (moved_piece.color == WHITE) {
            if (from_col == 0 && from_row == 7) {  // a-file rook
                board->whiterook_amoved = 0;
            } else if (from_col == 7 && from_row == 7) {  // h-file rook
                board->whiterook_hmoved = 0;
            }
        } else if (moved_piece.color == BLACK) {
            if (from_col == 0 && from_row == 0) {  // a-file rook
                board->blackrook_amoved = 0;
            } else if (from_col == 7 && from_row == 0) {  // h-file rook
                board->blackrook_hmoved = 0;
            }
        }
    }
    //king square update
    if(moved_piece.type == KING) {
        if(moved_piece.color == WHITE) {
            board->wkingsq[0] = from_row;
            board->wkingsq[1] = from_col;
        } else if(moved_piece.color == BLACK) {
            board->bkingsq[0] = from_row;
            board->bkingsq[1] = from_col;
        }
    }
}


















void undo_move(Move *move, Board *board){
    if (move->move_count == 0) {
        printf("No moves to undo.\n");
        return;
    }
    move->move_count--;
    MoveRecord *rec = &move->history[move->move_count];
    reverse_move(board, rec->from_row, rec->from_col, rec->to_row, rec->to_col, rec->moved_piece, rec->captured_piece);
    // Decrement captured piece count if there was a capture
    if(rec->captured_piece.type != EMPTY) {
        if (rec->captured_piece.color == WHITE) {
            board->whitecapturedcount--;
            board->whitecaptured[board->whitecapturedcount].type = EMPTY;
            board->whitecaptured[board->whitecapturedcount].color = EMPTY;
        } else if (rec->captured_piece.color == BLACK) {
            board->blackcapturedcount--;
            board->blackcaptured[board->blackcapturedcount].type = EMPTY;
            board->blackcaptured[board->blackcapturedcount].color = EMPTY;
        }
    }
    if(enpasswn(board, rec->from_row, rec->from_col, rec->to_row, rec->to_col)==1){
        if(rec->moved_piece.color==WHITE){
            board->square[rec->to_row + 1][rec->to_col] = (Piece){PAWN, BLACK};
        }
        else if(rec->moved_piece.color==BLACK){
            board->square[rec->to_row - 1][rec->to_col] = (Piece){PAWN, WHITE};
        }
    }
    if(rec->promoted_piece.type != EMPTY) {
        board->square[rec->from_row][rec->from_col] = rec->moved_piece;
    }
    move->undo_count++;
}
void redo_move(Move *move, Board *board) {
    if (move->move_count >= 100 || move->undo_count == 0) {
        printf("No moves to redo.\n");
        return;
    }
    MoveRecord *rec = &move->history[move->move_count];
    execute_move(board, rec->from_row, rec->from_col, rec->to_row, rec->to_col);
    move->move_count++;
    move->undo_count--;
    
    if(rec->promoted_piece.type != EMPTY) {
        board->square[rec->to_row][rec->to_col] = rec->promoted_piece;
    }
}