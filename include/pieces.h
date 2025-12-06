#ifndef PIECES_H
#define PIECES_H

typedef struct
{
    char king ;
    char queen ;
    char bishop ;
    char knight ;
    char rock ;
    char pawn ;
    char empty;

}Piecetype;

typedef struct{
    char white ;
    char black;
}Color;

typedef struct{
    Piecetype type;
    Color color;
}Piece;




#endif