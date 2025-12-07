#ifndef PIECES_H
#define PIECES_H

#define KING 0
#define QUEEN 1
#define ROCK 2
#define BISHOP 3
#define KNIGHT 4
#define PAWN 5
#define EMPTY 6

#define WHITE 1
#define BLACK 2


typedef struct{
    int type;
    int color;
}Piece;




#endif