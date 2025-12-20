#ifndef MOVE_H
#define MOVE_H
#include"board.h"
#include"game.h"
typedef struct {
    int from_row;
    int from_col;
    int to_row;
    int to_col;
    Piece moved_piece;
    Piece captured_piece;
    Piece movehistory[100][2]; // [][0] for moved piece, [][1] for captured piece
    int move_count;
} Move;
extern int input_as_int[4];  // global array
void convert_input_to_int(char *x);
int sign(int x);
int rook(int from_row,int from_col,int to_row,int to_col);
int king(int from_row,int from_col,int to_row,int to_col);
int bishop(int from_row,int from_col,int to_row,int to_col);
int knight(int from_row,int from_col,int to_row,int to_col);
int queen(int from_row,int from_col,int to_row,int to_col);
int path_check(Board *board,int from_row,int from_col,int to_row,int to_col);
int des_check(Board *board);
int castling_path_clear(Board *board,int king_row,int king_col,int rook_col);
int castling(Board *board,char *castl,Game *game);
int pawn_promotion(Board *board);
int enpasswn(Board *board,int fromrow,int fromcol,int torow,int tocol);
int change_pawn(Board *board);
void where_is_the_king(Board *board);
int can_attack(Board *board,int from_row,int from_col,int to_row,int to_col);
int is_king_checked(Board *board,Game *game);
int validation(char *x,Board *board, Game *game,int from_row,int from_col,int to_row,int to_col);
void initialize_move_history(Move *move);
void reverse_move(Board *board, int from_row, int from_col,
                 int to_row, int to_col, Piece moved_piece, Piece captured_piece);
void record_move(Move *move, Piece moved_piece, Piece captured_piece);
void undo_move(Move *move, Board *board);
void redo_move(Move *move, Board *board);
void execute_move(Board *board,int from_row, int from_col,int to_row,int to_col);



#endif