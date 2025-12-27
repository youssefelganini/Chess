#ifndef FILE_IO_H
#define FILE_IO_H
#include"game.h"

void save_game(Game *game, const char *filename, Move *move);
Game* load_game(const char *filename, Move *move);

#endif // FILE_IO_H