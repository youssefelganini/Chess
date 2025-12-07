#ifndef BOARD_H
#define BOARD_H
#define bsize 8
#include"pieces.h"

typedef struct 
{
    Piece square[bsize][bsize];
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

void initboard(Board b);
void displayboard();


#endif