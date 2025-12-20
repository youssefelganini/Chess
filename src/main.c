#include"C:\\Users\\Mega Store\\Desktop\\Uni\\Prog\\project\\Chess\\include\\game.h"
#include"C:\\Users\\Mega Store\\Desktop\\Uni\\Prog\\project\\Chess\\include\\board.h"
#include"C:\\Users\\Mega Store\\Desktop\\Uni\\Prog\\project\\Chess\\include\\move.h"
#include"C:\\Users\\Mega Store\\Desktop\\Uni\\Prog\\project\\Chess\\include\\pieces.h"
#include<stdio.h>
int main(){
    Game game;
    init_game(&game);
    game_loop(&game);

    return 0;
}