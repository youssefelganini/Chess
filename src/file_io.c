#include"C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\file_io.h"
#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\board.h"
#include "C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\game.h"
void save_game(Game *game, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Failed to open file for saving");
        return;
    }
    fprintf(file, "%d\n", game->current_player);
    fprintf(file, "%d\n", game->state);
    for(int i = 0; i < bsize; i++) {
        for(int j = 0; j < bsize; j++) {
            fprintf(file, "%d %d ", game->board.square[i][j].type, game->board.square[i][j].color);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "%d\n", game->board.whitecapturedcount);
    for(int i = 0; i < game->board.whitecapturedcount; i++) {
        fprintf(file, "%d %d ", game->board.whitecaptured[i].type, game->board.whitecaptured[i].color);
    }
    fprintf(file, "\n");
    fprintf(file, "%d\n", game->board.blackcapturedcount);
    for(int i = 0; i < game->board.blackcapturedcount; i++) {
        fprintf(file, "%d %d ", game->board.blackcaptured[i].type, game->board.blackcaptured[i].color);
    }
    fprintf(file, "\n");
    fprintf(file, "%d %d %d %d %d %d\n", game->board.whitekingmoved,
            game->board.blackkingmoved,
            game->board.whiterook_amoved,
            game->board.whiterook_hmoved,
            game->board.blackrook_amoved,
            game->board.blackrook_hmoved);
    fclose(file);
}
Game* load_game(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Failed to open file for loading");
        return NULL;
    }
    int current_player, state;
    if(fscanf(file, "%d\n", &current_player) != 1 ||
       fscanf(file, "%d\n", &state) != 1) {
        fclose(file);
        return NULL;
    }
    Game *game = (Game *)malloc(sizeof(Game));
    if (game == NULL) {
        perror("Failed to allocate memory for game");
        fclose(file);
        return NULL;
    }
    game->current_player = current_player;
    game->state = state;
    for(int i = 0; i < bsize; i++) {
        for(int j = 0; j < bsize; j++) {
            if(fscanf(file, "%d %d ", &game->board.square[i][j].type, &game->board.square[i][j].color) != 2) {
                free(game);
                fclose(file);
                return NULL;
            }
            game->board.square[i][j].type = game->board.square[i][j].type;
            game->board.square[i][j].color = game->board.square[i][j].color;
        }
        fscanf(file, "\n");
    }
    if(fscanf(file, "%d\n", &game->board.whitecapturedcount) != 1) {
        free(game);
        fclose(file);
        return NULL;
    }
    for(int i = 0; i < game->board.whitecapturedcount; i++) {
        if(fscanf(file, "%d %d ", &game->board.whitecaptured[i].type, &game->board.whitecaptured[i].color) != 2) {
            free(game);
            fclose(file);
            return NULL;
        }
        game->board.whitecaptured[i].type = game->board.whitecaptured[i].type;
        game->board.whitecaptured[i].color = game->board.whitecaptured[i].color;
    }
    fscanf(file, "\n");
    if(fscanf(file, "%d\n", &game->board.blackcapturedcount) != 1) {
        free(game);
        fclose(file);
        return NULL;
    }
    for(int i = 0; i < game->board.blackcapturedcount; i++) {
        if(fscanf(file, "%d %d ", &game->board.blackcaptured[i].type, &game->board.blackcaptured[i].color) != 2) {
            free(game);
            fclose(file);
            return NULL;
        }
        game->board.blackcaptured[i].type = game->board.blackcaptured[i].type;
        game->board.blackcaptured[i].color = game->board.blackcaptured[i].color;
    }
    fscanf(file, "\n");
    if(fscanf(file, "%d %d %d %d %d %d\n", &game->board.whitekingmoved,
            &game->board.blackkingmoved,
            &game->board.whiterook_amoved,
            &game->board.whiterook_hmoved,
            &game->board.blackrook_amoved,
            &game->board.blackrook_hmoved) != 6) {
        free(game);
        fclose(file);
        return NULL;
    }
    fclose(file);
    return game;
}