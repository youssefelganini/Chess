#ifndef BOARD_H
#define BOARD_H
#define bsize 8
#include"pieces.h"

Piecetype whitepieces;
whitepieces.king = 'k';
whitepieces.queen = 'q';
whitepieces.bishop = 'b';
whitepieces.pawn = 'p';
whitepieces.rock = 'r';
whitepieces.knight = 'n';
Piecetype blackpieces;
whitepieces.king = 'K';
whitepieces.queen = 'Q';
whitepieces.bishop = 'B';
whitepieces.pawn = 'P';
whitepieces.rock = 'R';
whitepieces.knight = 'N';


char init_pos[8][8] = {
{blackpieces.rock ,blackpieces.knight ,blackpieces.bishop ,blackpieces.queen ,blackpieces.king ,blackpieces.bishop ,blackpieces.knight ,blackpieces.rock },
{'.','-','.','-','.','-','.','-'},
{'-','.','-','.','-','.','-','.'},
{'.','-','.','-','.','-','.','-'},
{'-','.','-','.','-','.','-','.'},
{'.','-','.','-','.','-','.','-'},
{'-','.','-','.','-','.','-','.'},
{whitepieces.rock ,whitepieces.knight ,whitepieces.bishop ,whitepieces.queen ,whitepieces.king ,whitepieces.bishop ,whitepieces.knight ,whitepieces.rock }}


char boardColor[2] = {'.','-'};

void displayboard(){
    
}


#endif