#include"game.h"
#include"move.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"file_io.h"
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
    game->flag=0;
    
    printf("\nCurrent player: %s\n", 
           game->current_player == WHITE ? "White" : "Black");
           
    
     if (is_king_checked(&game->board,game)) {
         printf("CHECK!\n");
         game->flag=1;
     }
}

void game_loop(Game *game){
    printf("Welcome to Chess!\n");
    printf("Commands:\n");
    printf("Enter moves in the format 'e2e4' to move a piece from e2 to e4.\n");
    printf("Type 'save <filename>' to save the current game.\n");
    printf("Type 'load <filename>' to load a saved game.\n");
    printf("Type 'exit' to quit the game.\n");
    char input[100];
    int fromrow ,torow,fromcol,tocol;
    Move move;
    while(game->state == ONGOING){
        initialize_move_history(&move);
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
        if (strncmp(input, "save ", 5) == 0) {
            char filename[95];
            sscanf(input + 5, "%s", filename);
            save_game(game, filename);
            printf("======================================\n");
            printf("Game saved to %s\n", filename);
            continue;
        }
        if(strncmp(input, "load ", 5) == 0) {
            char filename[95];
            sscanf(input + 5, "%s", filename);
            Game *loaded_game = load_game(filename);
            if (loaded_game != NULL) {
                *game = *loaded_game;
                free(loaded_game);
                printf("Game loaded from %s\n", filename);
            } else {
                printf("Failed to load game from %s\n", filename);
            }
            continue;
        }
        printf("======================================\n");

        if(strncmp(input,"undo",4)==0){
            undo_move(&move,&game->board);
            continue;
        }

        if(strncmp(input,"redo",4)==0){
            redo_move(&move,&game->board);
            continue;
        }

        castling(&game->board,input,game);
        convert_input_to_int(input);
        fromcol = input_as_int[0];
        fromrow = input_as_int[1];
        tocol = input_as_int[2];
        torow = input_as_int[3];

        if (!validation(input,&game->board, game,fromrow,fromcol,torow,tocol)) {
            continue;
        }

        enpasswn(&game->board,fromrow,fromcol,torow,tocol);
        execute_move(&game->board,fromrow,fromcol,torow,tocol);
        if(is_king_checked(&game->board,game)){
            if(game->flag==1){
                printf("YOUR KING IS STILL IN CHECK!\n");}
            else printf("YOUR KING WILL BE IN CHECK!\n");
            reverse_move(&game->board,fromrow,fromcol,torow,tocol,
                         game->board.square[torow][tocol],
                         game->board.square[fromrow][fromcol]);
                         continue;
        }
        change_pawn(&game->board);


        if (game->current_player == WHITE){
            game->current_player = BLACK;
        }
        else{
            game->current_player = WHITE;
        }
        

    }
}