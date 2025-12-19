#include"/mnt/d/study/programming/Project/Chess/include/game.h"
#include"/mnt/d/study/programming/Project/Chess/include/board.h"
#include"/mnt/d/study/programming/Project/Chess/include/move.h"
#include"/mnt/d/study/programming/Project/Chess/include/pieces.h"
#include<stdio.h>
int main(){
    Game game;
    init_game(&game);
    game_loop(&game);

    return 0;
}