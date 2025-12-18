#ifndef BOARD_H
#define BOARD_H
#define bsize 8
#include"pieces.h"

typedef struct 
{
    Piece square[bsize][bsize];
    Piece whitecaptured[16];
    Piece blackcaptured[16];
    int whitecapturedcount;
    int blackcapturedcount;
    int whitekingmoved;
    int blackkingmoved;
    int whiterook_amoved;
    int whiterook_hmoved;
    int blackrook_amoved;
    int blackrook_hmoved;
}Board;




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

void initboard(Board *b);
void displayboard(Board *b);
char piece_char(Piece p);
void capturedpieces(Board *b);


#endif