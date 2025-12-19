#ifndef MOVE_H
#define MOVE_H
#include"C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\board.h"
#include"C:\Users\Mega Store\Desktop\Uni\Prog\project\Chess\include\game.h"
extern int input_as_int[4];  // global array
void convert_input_to_int(char *x);
int sign(int x);
int rook();
int king();
int bishop();
int knight();
int queen();
int path_check(Board *board);
int des_check(Board *board);
int castling_path_clear(Board *board,int king_row,int king_col,int rook_col);
int castling(Board *board,char *castl,Game *game);
//int pawn_promotion(Board *board);
int change_pawn(Board *board);
int is_king_checked(Board *board);
int validation(char *x,Board *board);
void execute_move(Board *board,int from_row, int from_col,int to_row,int to_col);



#endif