#ifndef GAME_H
#define GAME_H
#include"board.h"
#define GAME_ONGOING 0
#define GAME_WHITE_WIN 1 
#define GAME_BLACK_WIN 2
#define GAME_DRAW 3


typedef struct {
    Board board;
    int current_player;
    int state;
} Game;


void init_game(Game *game);
void game_loop(Game *game);
int set_move(char *input, int *fromrow, int *fromcol,int *torow, int *tocol);



#endif