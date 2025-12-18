#ifndef MOVE_H
#define MOVE_H
#include"C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\board.h"
#include"game.h"
int input_as_int[4];  // global array
void convert_input_to_int(char *x);
int sign(int x);
int rook();
int king();
int bishop();
int path_check(Board *b);
int dest_check(Board*b);
int castling_path_clear(Board *b,int king_row,int king_col,int rook_col);
// int castling(Board *b, char *castl , Game *game);
int validation(char *x,Board *b);
void execute_move(Board *board, int from_row, int from_col,
                 int to_row, int to_col);


#endif