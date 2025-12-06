#ifndef BOARD_H
#define BOARD_H
#define bsize 8
#include"pieces.h"

Piece white;
Piece black;
white.piece.king = 'k';
white.piece.queen = 'q';
white.piece.rock = 'r';
white.piece.bishop = 'b';
white.piece.knight = 'n';
white.piece.pawn = 'p';
black.piece.king = 'K';
black.piece.queen = 'Q';
black.piece.rock = 'R';
black.piece.bishop = 'B';
black.piece.knight = 'N';
black.piece.pawn = 'P';



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

void displayboard();


#endif