#include"C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\board.h"
#include<stdio.h>

char boardlayout[8][8] = {
{'-','.','-','.','-','.','-','.'},
{'.','-','.','-','.','-','.','-'},
{'-','.','-','.','-','.','-','.'},
{'.','-','.','-','.','-','.','-'},
{'-','.','-','.','-','.','-','.'},
{'.','-','.','-','.','-','.','-'},
{'-','.','-','.','-','.','-','.'},
{'.','-','.','-','.','-','.','-'}};

char boardColor[2] = {'.','-'};
void initboard(Board *b){
    int ppos[8] = {ROOK , KNIGHT , BISHOP , QUEEN , KING , BISHOP , KNIGHT , ROOK };

    for(int i = 0 ; i < bsize ; ++i){
        b->square[7][i].type = ppos[i];
        b->square[7][i].color = WHITE;
        b->square[6][i].type = PAWN;
        b->square[6][i].color = WHITE;
    }
    for(int i = 0 ; i < bsize ; ++i){
        b->square[0][i].type = ppos[i];
        b->square[0][i].color = BLACK;
        b->square[1][i].type = PAWN;
        b->square[1][i].color = BLACK;
    }
    for(int i = 2 ; i < 6 ; ++i){
        for(int j = 0 ; j < bsize ; ++j){
            b->square[i][j].type = EMPTY;
            b->square[i][j].color = EMPTY;
        }
    }
}

char piece_char(Piece p){
    if(p.color == BLACK){
        switch (p.type)
        {
        case PAWN:
            return 'p';
        case ROOK:
            return 'r';
        case KNIGHT:
            return 'n';
        case BISHOP:
            return 'b';
        case QUEEN:
            return 'q';
        case KING:
            return 'k';
        default:
            return ' ';
        }
    }
    else if (p.color == WHITE){
        switch (p.type)
        {
        case PAWN:
            return 'P';
        case ROOK:
            return 'R';
        case KNIGHT:
            return 'N';
        case BISHOP:
            return 'B';
        case QUEEN:
            return 'Q';
        case KING:
            return 'K';
        default:
            return ' ';
        }
    }
    return ' ';
}

void displayboard(Board *b){
    int num= 8;
    printf("\n   ");
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
    num--;
    }
    printf("   ");

for(int i = 0 ; i < 8 ; ++i){
    printf("+---");
}
printf("+\n");
}

void capturedpieces(Board *b) {
    b->blackcapturedcount = 0;
    b->whitecapturedcount = 0;
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
