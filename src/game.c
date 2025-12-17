#include"include\game.h"

void init_game(Game *game) {
    init_board(&game->board);
    game->current_player = WHITE;
    game->state = GAME_ONGOING;
}

void print_game_state(Game *game) {
    displayboard(&game->board);
    capturedpieces(&game->board);
    
    printf("\nCurrent player: %s\n", 
           game->current_player == WHITE ? "White" : "Black");
    
    if (/*king is in check*/) {
        printf("CHECK!\n");
    }
}

