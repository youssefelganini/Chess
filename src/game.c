#include"/mnt/d/study/programming/Project/Chess/include/game.h"
#include"/mnt/d/study/programming/Project/Chess/include/move.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"/mnt/d/study/programming/Project/Chess/include/file_io.h"
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
    initialize_move_history(&move);
    while(game->state == ONGOING){
        
        print_game_state(game);
        
         Board tempboard = game->board;


        if(chekmate(&game->board,&move,game)){
            printf("WON");
            break;
        }
        if(stalmate(&tempboard,game)||draw(&game->board,game)){
            printf("DRAW!");
            break;
        } 
        if (is_king_checked(&game->board,game)) {
            printf("CHECK!\n");
            game->flag=1;
        }      


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
            if(game->current_player == WHITE){
                game->current_player = BLACK;
            }
            else{
                game->current_player = WHITE;
            }
            continue;
        }

        if(strncmp(input,"redo",4)==0 && move.undo_count>0){
            redo_move(&move,&game->board);
            if(game->current_player == WHITE){
                game->current_player = BLACK;
            }
            else{
                game->current_player = WHITE;
            }
            continue;
        }

       
        convert_input_to_int(input);
        fromcol = input_as_int[0];
        fromrow = input_as_int[1];
        tocol = input_as_int[2];
        torow = input_as_int[3];




         if(castling(input,game,&game->board, &move)){
             if (game->current_player == WHITE){
             game->current_player = BLACK;
             }
             else{
             game->current_player = WHITE;
             } 
             continue;  
         }

        if (!validation(&game->board, game,fromrow,fromcol,torow,tocol)) {
            continue;
        }
        enpasswn(&tempboard, &move, fromrow, fromcol, torow, tocol);
        execute_move(&tempboard,fromrow,fromcol,torow,tocol);
        if(is_king_checked(&tempboard,game)){
            if(game->flag==1){
                printf("YOUR KING IS STILL IN CHECK!\n");}
                else {
                    printf("YOUR KING WILL BE IN CHECK!\n");
                    
                }
                continue;
            }
            
            
            
        Piece moved_piece = game->board.square[fromrow][fromcol];
        Piece captured_piece = game->board.square[torow][tocol];
        record_move(&move, fromrow, fromcol, torow, tocol, moved_piece, captured_piece, &game->board);
        enpasswn(&game->board, &move, fromrow, fromcol, torow, tocol);
        execute_move(&game->board,fromrow,fromcol,torow,tocol);
        change_pawn(&game->board,&move);
        
        if (game->current_player == WHITE){
            game->current_player = BLACK;
        }
        else{
            game->current_player = WHITE;
        }
        

    }
}