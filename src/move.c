#include "C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\move.h"
#include<math.h>
#include<stdio.h>
#include"C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\board.h"
#include <stdlib.h>
#include"C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\game.h"

int flag=0;
int counter=0;


/*we didnot write in validition if teh rook return 0 what it will print
x is the input
a  has the values of the input as int
c array for castling
checkoftheking
checkmate
*/
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
int rook(){ /*input=[a,3,a,4]*/
    if(input_as_int[0]==input_as_int[2]&&input_as_int[1]!=input_as_int[3]) return 1;
    if(input_as_int[0]!=input_as_int[2]&&input_as_int[1]==input_as_int[3]) return 1;
    return 0;
}
int king(){
    if(abs(input_as_int[0]-input_as_int[2])<=1 &&
        abs(input_as_int[1]-input_as_int[3])<=1) return 1;

    return 0;
}

int bishop(){
    if(abs(input_as_int[2]-input_as_int[0])==abs(input_as_int[3]-input_as_int[1])) return 1;
    return 0;
}


int knight(){
if(((abs(input_as_int[0]-input_as_int[2])==2) && (abs(input_as_int[1]-input_as_int[3])==1)) || 
   ((abs(input_as_int[0]-input_as_int[2])==1) && (abs(input_as_int[1]-input_as_int[3])==2))) return 1;
   return 0;
}
int queen(){
    if(rook()||bishop()) return 1;
    return 0;
}
/*----------------------------------------------------------------------------------------------------------*/
int path_check(Board *board){
    int dx=sign(input_as_int[2]-input_as_int[0]);
    int dy=sign(input_as_int[3]-input_as_int[1]);
    int x=dx+input_as_int[0];
    int y=dy+input_as_int[1];
    while (x!=input_as_int[2]||y!=input_as_int[3])
    {
        if(board->square[y][x].type!= EMPTY) return 0;
        x+=dx;
        y+=dy;
    }
    return 1;
}
int dest_check(Board*board){
    if(board->square[input_as_int[3]][input_as_int[2]].color==board->square[input_as_int[1]][input_as_int[0]].color ) return 0;
    return 1;
}
/*----------------------------------------------------------------------------------------------------------*/
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
int castling(Board *board,char *castl,Game *game){
    convert_input_to_int(castl);
    char piece=piece_char(board->square[input_as_int[1]][input_as_int[0]]);
    if(is_king_checked(board)){
        printf("You cannot castle while your king is in check\n");
        return 0;
    }
    if(game->current_player==WHITE){
        if(piece!='K') return 0;
        if(input_as_int[2]==6&&input_as_int[3]==7){
            if(board->whitekingmoved!=0&&board->whiterook_hmoved!=0){
                printf("You cannot castle, king or rook has moved\n");
                return 0;
            }
            if(board->square[7][4].type!=KING||board->square[7][7].type!=ROOK) return 0;
            if(!castling_path_clear(board,7,4,7)){
                printf("Cannot castle, path blocked\n");
                return 0;
            }
            execute_move(board,7,4,7,6);
            execute_move(board,7,7,7,5);
            return 1;
        } else if(input_as_int[2]==2&&input_as_int[3]==7){
            if(board->whitekingmoved!=0&&board->whiterook_amoved!=0){
                printf("You cannot castle, king or rook has moved\n");
                return 0;
            }
            if(board->square[7][4].type!=KING||board->square[7][0].type!=ROOK) return 0;
            if(!castling_path_clear(board,7,4,0)){
                printf("Cannot castle, path blocked\n");
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
            if(board->blackkingmoved!=0&&board->blackrook_hmoved!=0){
                printf("You cannot castle, king or rook has moved\n");
                return 0;
            }
            if(board->square[0][4].type!=KING||board->square[0][7].type!=ROOK) return 0;
            if(!castling_path_clear(board,0,4,7)){
                printf("Cannot castle, path blocked\n");
                return 0;
            }
            execute_move(board,0,4,0,6);
            execute_move(board,0,7,0,5);
            return 1;
        } else if(input_as_int[2]==2&&input_as_int[3]==0){
            if(board->blackkingmoved!=0&&board->blackrook_amoved!=0){
                printf("You cannot castle, king or rook has moved\n");
                return 0;
            }
            if(board->square[0][4].type!=KING||board->square[0][0].type!=ROOK) return 0;
            if(!castling_path_clear(board,0,4,0)){
                printf("Cannot castle, path blocked\n");
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



/*----------------------------------------------------------------------------------------------------------*/
int pawn_promotion(Board *board){
    if(board->square[0][input_as_int[2]].type==PAWN &&
       board->square[0][input_as_int[2]].color==WHITE){
        return 1;
    }
    if(board->square[7][input_as_int[2]].type==PAWN &&
       board->square[7][input_as_int[2]].color==BLACK){
        return 1;
    }
    return 0;
}
int change_pawn(Board *board){
    if(pawn_promotion(board)){
        char promotion;
        printf("Enter which piece you want\n");
        scanf(" %c",&promotion);
        switch(promotion){
            case 'Q':
            case 'q': board->square[input_as_int[3]][input_as_int[2]].type=QUEEN; break;
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
        return 1;
    }
    return 0;
}
/*----------------------------------------------------------------------------------------------------------*/
int enpasswn(Board *board){
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
/*----------------------------------------------------------------------------------------------------------*/

int is_king_checked(Board *board){
    (void)board; 
    return 0;    
}

/*----------------------------------------------------------------------------------------------------------*/
int validation(char *x,Board *board, Game *game){
    if(x[0]<'a' || x[0]>'h' || x[2]<'a' || x[2]>'h' || 
            x[1]<'1' || x[1]>'8' || x[3]<'1' || x[3]>'8') {
        printf("Invalid input, must be in the range of (a-h) and (1-8)\n");
        return 0;
    }
    convert_input_to_int(x);
    if(game->current_player==WHITE){
        if(board->square[input_as_int[1]][input_as_int[0]].color==BLACK){
            printf("\nIt's White's turn. Please move a White piece.\n");
            return 0;
        }
    }
    else if(game->current_player==BLACK){
        if(board->square[input_as_int[1]][input_as_int[0]].color==WHITE){
            printf("\nIt's Black's turn. Please move a Black piece.\n"); 
            return 0;
        }
    }
    if(board->square[input_as_int[1]][input_as_int[0]].type == EMPTY){
        printf("You cannot move an empty square\n");
        return 0;
    }
    if(dest_check(board)==0){
        printf("You cannot capture your own piece\n");
        return 0;
    }


    char piece=piece_char(board->square[input_as_int[1]][input_as_int[0]]); /*current piece*/
    if(x[0]==x[2]&&x[1]==x[3]) {
        printf("Invlaid input ,you didnot move the piece\n");
        return 0;}
    if(x[0]<'a' || x[0]>'h' || x[2]<'a' || x[2]>'h' || 
            x[1]<'1' || x[1]>'8' || x[3]<'1' || x[3]>'8') {
        printf("Invalid input, must be in the range of (a-h) and (1-8)\n");
        return 0;
    }
    switch (piece)
    {
    case 'R':
    case 'r':
        if(path_check(board)==0){
           printf("Path is blocked\n");
            return 0;
        }
        return rook();
    case 'b':
    case 'B':
        if(path_check(board)==0){
            printf("Path is blocked\n");
            return 0;
        }
        return bishop();
    case 'q':
    case 'Q':
        if(path_check(board)==0){
            printf("Path is blocked\n");
            return 0;
        }
        return queen();
    case 'N':
    case 'n':
        return knight();
    case 'K':
    case 'k':
        return king();
    case 'P':
         if(x[1]=='2'  && x[0]==x[2] ){
            if(x[3]=='4'){
                 if(path_check(board)==0){
                     printf("Path is blocked\n");
                    return 0;
                }
                if(board->square[input_as_int[3]][input_as_int[2]].type!= EMPTY) {
                    printf("Canot move here the square is not empty\n");
                    return 0;
                }     
            return 1;              
            }
        }
        if(input_as_int[3]==input_as_int[1]-1 &&input_as_int[0]==input_as_int[2]) {
           if(board->square[input_as_int[3]][input_as_int[2]].type!= EMPTY) {
                printf("Canot move here the square is not empty\n");
                return 0;
            }/*check for pawn if there is piece a black piece or white where it goes*/
            else{
                return 1;
            }
        }
        if(input_as_int[1]==3&&board->enpassen_col==input_as_int[2]&&board->enpassen_row==input_as_int[3]) return 1;
        if(input_as_int[3]==input_as_int[1]-1 &&(input_as_int[2]==input_as_int[0]+1||input_as_int[2]==input_as_int[0]-1)){
            if(board->square[input_as_int[3]][input_as_int[2]].color!=BLACK){
                printf("This move is invalid\n");
                return 0;
            }
            return 1;
        }
        printf("The pawn canot move like that");
        return 0;
    case 'p':
        if(x[1]=='7' && x[2]==x[0]){
            if(x[3]=='5'){
                if(path_check(board)==0){
                    printf("Path is blocked\n");  
                    return 0;
                }
                if(board->square[input_as_int[3]][input_as_int[2]].type!= EMPTY) {
                    printf("Canot move here the square not empty\n");
                    return 0;
                }
                return 1;
            }
        }
        if(input_as_int[3]==input_as_int[1]+1 &&input_as_int[0]==input_as_int[2]) {
            if(board->square[input_as_int[3]][input_as_int[2]].type!= EMPTY) {
                printf("Canot move here the square is not empty\n");
                return 0;
            }/*check for pawn if there is  a black piece or white where it goes*/
            else{
                return 1;
            }
        }
        if(input_as_int[1]==4&&board->enpassen_col==input_as_int[2]&&board->enpassen_row==input_as_int[3]) return 1;
        if(input_as_int[3]==input_as_int[1]+1 &&(input_as_int[2]==input_as_int[0]+1||input_as_int[2]==input_as_int[0]-1)){
            if(board->square[input_as_int[3]][input_as_int[2]].color!=WHITE ){
                printf("This move is invalid\n");
                return 0;
            }
            return 1;
        }
        printf("The pawn canot move like that");
        return 0;
        
    default:
        printf("Invalid input,This square has no pieces\n");
        return 0;
    }

}
/*----------------------------------------------------------------------------------------------------------*/
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
        } else if(moving_piece.color == BLACK) {
            board->blackkingmoved = 1;
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

    if(moving_piece.type == PAWN && to_row == board->enpassen_row && to_col == board->enpassen_col) {
        if(moving_piece.color == WHITE) {
            board->square[board->enpassen_row - 1][board->enpassen_col].type = EMPTY;
            board->square[board->enpassen_row - 1][board->enpassen_col].color = EMPTY;
        } else if(moving_piece.color == BLACK) {
            board->square[board->enpassen_row + 1][board->enpassen_col].type = EMPTY;
            board->square[board->enpassen_row + 1][board->enpassen_col].color = EMPTY;
        }
    }
}



/*----------------------------------------------------------------------------------------------------------*/

/*void initialize_move_history(Move *move) {
    move->move_count = 0;
}
void record_move(Move *move, Piece moved_piece, Piece captured_piece) {
    move->movehistory[move->move_count][0] = moved_piece;
    move->movehistory[move->move_count][1] = captured_piece;
    move->move_count++;
}
void reverse_move(Board *board, int from_row, int from_col,
                 int to_row, int to_col, Piece moved_piece, Piece captured_piece) {
    board->square[from_row][from_col] = moved_piece;
    board->square[to_row][to_col] = captured_piece;
    if(captured_piece.type != EMPTY) {
        if (captured_piece.color == WHITE) {
            board->whitecapturedcount--;
        } else {
            board->blackcapturedcount--;
        }
    }
}*/
// void undo_move(Move *move, Board *board) {
//     if (move->move_count == 0) {
//         printf("No moves to undo.\n");
//         return;
//     }
//     move->move_count--;
//     Piece moved_piece = move->movehistory[move->move_count][0];
//     Piece captured_piece = move->movehistory[move->move_count][1];
//     if(moved_piece.type == EMPTY) {
//         printf("No moves to undo.\n");
//         return;
//     }
//     reverse_move(board, input_as_int[1], input_as_int[0],
//                  input_as_int[3], input_as_int[2], moved_piece, captured_piece);
// }
// void redo_move(Move *move, Board *board) {
//     if (move->move_count >= 100) {
//         printf("No moves to redo.\n");
//         return;
//     }
//     Piece moved_piece = move->movehistory[move->move_count][0];
//     Piece captured_piece = move->movehistory[move->move_count][1];
//     move->move_count++;
//     if (moved_piece.type == EMPTY) {
//         printf("No moves to redo.\n");
//         return;
//     }
//     if(move->movehistory[move->move_count - 1][1].type != EMPTY) {
//         if (captured_piece.color == WHITE) {
//             board->blackcaptured[board->blackcapturedcount++] = captured_piece;
//         } else {
//             board->whitecaptured[board->whitecapturedcount++] = captured_piece;
//         }
//     }
// }