#ifndef FILE_IO_H
#define FILE_IO_H
#include"game.h"

void save_game(Game *game, const char *filename);
Game* load_game(const char *filename);

#endif // FILE_IO_H