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
    int white ;
    int black;
}Color;


#endif