#include "Uni\Prog\project\Chess\include\board.h"

void displayboard(){
    int c = 8 ; 
    int j = 7;
    int num= 1;
    printf("   ");
    for (int i = 0 ; i < 8 ; ++i){
        printf("  %c ",'A'+i);
    } printf("\n");
    while(c>0){
        printf("   ");
    for (int i = 0 ; i < 8 ; ++i){
        printf("+---");
    }
    printf("+\n %d ",num);
    for (int i = 0 ; i < 8 ;++i){
        printf("| %c ",boardlayout[j][i]);
    }
    printf("|\n");
    c--;
    j--;
    num++;
}
    printf("   ");

for (int i = 0 ; i < 8 ; ++i){
    printf("+---");
}
printf("+\n");
}


void initboard(Board b){
    int ppos[8] = {ROCK , KNIGHT , BISHOP , QUEEN , KING , BISHOP , KNIGHT , ROCK };

    for(int i = 0 ; i < bsize ; ++i){
        b.square[0][i].type = ppos[i];
        b.square[0][i].color = WHITE;
        b.square[1][i].type = PAWN;
        b.square[1][i].color = WHITE;
    }
    for(int i = 0 ; i < bsize ; ++i){
        b.square[6][i].type = ppos[i];
        b.square[6][i].color = BLACK;
        b.square[7][i].type = PAWN;
        b.square[7][i].color = BLACK;
    }

    for(int i = 2 ; i < 6 ; ++i){
        for(int j = 0 ; j < bsize ; ++j){
            b.square[i][j].type = EMPTY;
            b.square[i][j].color = EMPTY;
        }
    }
}