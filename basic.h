#ifndef BASIC_h
#define BASIC_h
#include "status.h"
#include <time.h>  

typedef void* BOARD; 


struct board {
	char* layout;
};
typedef struct board Board; 

/*
	Clears the keyboard buffer. 
*/
void clearKeyboardBuffer(void);

/*
	Initialize board for tic-tac-toe
*/
BOARD init_board();

/*
	Destroy the board once the game has finished
*/
void destroy_board(BOARD* game_board);

/*
	Print board with current standings. 
*/
void print_board(BOARD game_board);

/*
	Check if there is a winner. Return FALSE is there is no winner and TRUE if there is. 
*/
BOOL check_winner(BOARD game_board);

/*
	Place the marker on the board. Return failure if the player tries to place a marker where there is already a marker or if the 
	placement is out of range. 
*/
STATUS place_marker(BOARD game_board, char player, char other_player, int placement);

/*
	Place the marker on the board. This is the same as place marker function but is used by AI (with error messages surpressed)
*/
STATUS place_marker_ai(BOARD game_board, char ai, char player, int placement);

/*
	Returns 1 if heads and 0 if odd. 
*/
int coin_flip();

/*
	Check if there is a draw 
*/
BOOL check_if_draw(BOARD game_board, char player_1, char player_2);

/*
	Random number generator. Returns a random number.
*/

int random_number_generator();

#endif 