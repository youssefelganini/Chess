#include"C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\game.h"
#include"C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\move.h"
#include<stdio.h>
#include<string.h>

// void deattachinputs(char *x , int from_r , int to_r , int from_c ,int to_c ){
//     from_c = x[0];
//     from_r = x[1];
//     to_c = x[2];
//     to_r = x[3];
// }

void init_game(Game *game) {
    initboard(&game->board);
    game->current_player = WHITE;
    game->state = ONGOING;
}

void print_game_state(Game *game) {
    displayboard(&game->board);
    capturedpieces(&game->board);
    
    printf("\nCurrent player: %s\n", 
           game->current_player == WHITE ? "White" : "Black");
    
    // if (/*king is in check*/) {
    //     printf("CHECK!\n");
    // }
}

void game_loop(Game *game){
    char input[100];
    int fromrow ,torow,fromcol,tocol;
    while(game->state == ONGOING){
        print_game_state(game);
        printf("\nEnter :");
        if(fgets(input,100,stdin) == NULL){
            break;
        }
        convert_input_to_int(input);
        fromcol = input_as_int[0];
        fromrow = input_as_int[1];
        tocol = input_as_int[2];
        torow = input_as_int[3];
        if (!validation(input,&game->board)){
            continue;
        }
        execute_move(&game->board,fromrow,fromcol,torow,tocol);

        if (game->current_player == WHITE){
            game->current_player = BLACK;
        }
        else{
            game->current_player = WHITE;
        }
        
        if (strcmp(input,"exit")==0) { printf("\ngoodbye\n");break;}

    }
}