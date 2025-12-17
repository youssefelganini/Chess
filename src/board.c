#include"C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\board.h"
#include<stdio.h>
void initboard(Board *b){
    int ppos[8] = {ROCK , KNIGHT , BISHOP , QUEEN , KING , BISHOP , KNIGHT , ROCK };

    for(int i = 0 ; i < bsize ; ++i){
        b->square[0][i].type = ppos[i];
        b->square[0][i].color = WHITE;
        b->square[1][i].type = PAWN;
        b->square[1][i].color = WHITE;
    }
    for(int i = 0 ; i < bsize ; ++i){
        b->square[7][i].type = ppos[i];
        b->square[7][i].color = BLACK;
        b->square[6][i].type = PAWN;
        b->square[6][i].color = BLACK;
    }
    for(int i = 2 ; i < 6 ; ++i){
        for(int j = 0 ; j < bsize ; ++j){
            b->square[i][j].type = EMPTY;
            b->square[i][j].color = EMPTY;
        }
    }
}

char piece_char(Piece p){
    if(p.color == WHITE){
        switch (p.type)
        {
        case PAWN:
            return 'p';
            break;
        case ROCK:
            return 'r';
            break;
        case KNIGHT:
            return 'n';
            break;
        case BISHOP:
            return 'b';
            break;
        case QUEEN:
            return 'q';
            break;
        case KING:
            return 'k';
            break;
        default:
            break;
        }
    }
    else if (p.color == BLACK){
        switch (p.type)
        {
        case PAWN:
            return 'P';
            break;
        case ROCK:
            return 'R';
            break;
        case KNIGHT:
            return 'N';
            break;
        case BISHOP:
            return 'B';
            break;
        case QUEEN:
            return 'Q';
            break;
        case KING:
            return 'K';
            break;
        default:
            break;
        }
    }
    else{
        return ' ';
    }
}

void displayboard(Board *b){
    int num= 1;
    printf("   ");
    for (int i = 0 ; i < 8 ; ++i){
        printf("  %c ",'A'+i);
    } printf("\n");
    for (int i = 0 ; i < 8 ; ++i){
        printf("   ");
        for(int k =0 ; k < 8 ; ++k){
        printf("+---");
        }
    
    printf("+\n %d ",num);

        for(int j = 0 ; j < 8 ; ++j){
            if(b->square[i][j].type!=EMPTY){
                printf("| %c ",piece_char(b->square[i][j]));
            }
            else{
                printf("| %c ",boardlayout[j][i]);
            }
        }
    
    printf("|\n");
    num++;
    }
    printf("   ");

for(int i = 0 ; i < 8 ; ++i){
    printf("+---");
}
printf("+\n");
}

void display_captured_pieces(Board *b) {
    printf("\nCaptured Pieces:\n");
    printf("White captured: ");
    for (int i = 0; i < b->whitecapturedcount; i++) {
        printf("%c ", piece_char(b->whitecaptured[i]));
    }
    printf("\n");
    
    printf("Black captured: ");
    for (int i = 0; i < b->blackcapturedcount; i++) {
        printf("%c ", piece_char(b->blackcaptured[i]));
    }
    printf("\n");
}
