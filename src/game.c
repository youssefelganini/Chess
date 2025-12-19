#include"C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\game.h"
#include"C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\move.h"
#include<stdio.h>
#include<string.h>
void tolowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

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
    printf("Welcome to Chess!\n");
    printf("Enter moves in the format 'e2e4' to move a piece from e2 to e4.\n");
    printf("Type 'exit' to quit the game.\n");
    char input[100];
    int fromrow ,torow,fromcol,tocol;
    while(game->state == ONGOING){
        print_game_state(game);
        printf("\nEnter :");
        if(fgets(input,100,stdin) == NULL){
            break;
        }
        tolowercase(input);
        if (strcmp(input,"exit\n")==0){
            printf("\ngoodbye\n");
            break;
        }
        printf("======================================\n");
        convert_input_to_int(input);
        fromcol = input_as_int[0];
        fromrow = input_as_int[1];
        tocol = input_as_int[2];
        torow = input_as_int[3];
        if (!validation(input,&game->board, game)) {
            continue;
        }
        execute_move(&game->board,fromrow,fromcol,torow,tocol);

        if (game->current_player == WHITE){
            game->current_player = BLACK;
        }
        else{
            game->current_player = WHITE;
        }
        

    }
}