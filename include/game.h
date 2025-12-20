#ifndef GAME_H
#define GAME_H
#include"board.h"
#define ONGOING 0
#define WHITE_WIN 1 
#define BLACK_WIN 2
#define DRAW 3


typedef struct {
    Board board;
    int current_player;
    int state;
    int flag;
} Game;

void init_game(Game *game);
void game_loop(Game *game);
int set_move(char *input, int *fromrow, int *fromcol,int *torow, int *tocol);



#endif