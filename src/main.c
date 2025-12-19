#include"game.h"
#include"board.h"
#include"move.h"
#include"pieces.h"
#include<stdio.h>
int main(){
    Game game;
    init_game(&game);
    game_loop(&game);

    return 0;
}