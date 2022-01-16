#include <stdio.h>
#include <stdlib.h>
#include "basic.h"
#include <time.h>


void clearKeyboardBuffer(void) {							
	char ch;
	int ret;
	ret = scanf("%c", &ch);
	while (ret == 1 && ch != '\n' && ch != '\0') {
		ret = scanf("%c", &ch);
	}
}

BOARD init_board(){
	Board* board;
	board = (Board*)malloc(sizeof(board));
	if (board == NULL) {
		printf("Unable to allocate memory for Board!");
		exit(1); 
	}

	board->layout = (char*)malloc(sizeof(char) * 10);
	if (board->layout == NULL) {
		printf("Unable to allocate memory for Board!");
		exit(1); 
	}

for (int i = 1; i < 10; i++) {
	board->layout[i] = i + '0';
}

return (BOARD)board;
}

void destroy_board(BOARD* game_board) {
	Board* board = (Board*)game_board;
	free(board->layout);
	free(board);
	board = NULL;
	return;
}


void print_board(BOARD game_board) {
	Board* board = (Board*)game_board;

	printf("   |   |   \n");
	printf(" %c | %c | %c \n", board->layout[1], board->layout[2], board->layout[3]);
	printf("___|___|___\n");
	printf("   |   |   \n");
	printf(" %c | %c | %c \n", board->layout[4], board->layout[5], board->layout[6]);
	printf("___|___|___\n");
	printf("   |   |   \n");
	printf(" %c | %c | %c \n", board->layout[7], board->layout[8], board->layout[9]);
	printf("   |   |   \n");
}

BOOL check_winner(BOARD game_board) {
	Board* board = (Board*)game_board;

	//conditions where there is a winner
	if (board->layout[1] == board->layout[2] && board->layout[2] == board->layout[3]) {
		return TRUE;
	}

	if (board->layout[1] == board->layout[5] && board->layout[5] == board->layout[9]) {
		return TRUE;
	}

	if (board->layout[1] == board->layout[4] && board->layout[4] == board->layout[7]) {
		return TRUE;
	}

	if (board->layout[2] == board->layout[5] && board->layout[5] == board->layout[8]) {
		return TRUE;
	}

	if (board->layout[3] == board->layout[5] && board->layout[5] == board->layout[7]) {
		return TRUE;
	}

	if (board->layout[3] == board->layout[6] && board->layout[6] == board->layout[9]) {
		return TRUE;
	}

	if (board->layout[4] == board->layout[5] && board->layout[5] == board->layout[6]) {
		return TRUE;
	}

	if (board->layout[7] == board->layout[8] && board->layout[8] == board->layout[9]) {
		return TRUE;
	}
	return FALSE;
}

STATUS place_marker(BOARD game_board, char player, char other_player, int placement) {
	Board* board = (Board*)game_board;

	if (placement < 1 || placement > 9) {
		printf("Placement out of range! Please choose a valid spot between 1 and 9!\n");
		return FAILURE;
	}

	if (board->layout[placement] == player || board->layout[placement] == other_player) {
		printf("Space already taken!\n");
		return FAILURE;
	}
	else {
		board->layout[placement] = player;
		return SUCCESS;
	}

}

STATUS place_marker_ai(BOARD game_board, char ai, char player, int placement) {
	Board* board = (Board*)game_board;

	if (placement < 1 || placement > 9) {
		return FAILURE;
	}

	if (board->layout[placement] == player || board->layout[placement] == ai) {
		
		return FAILURE;
	}
	else {
		board->layout[placement] = ai;
		return SUCCESS;
	}

}

int coin_flip() {
	srand((unsigned int)time(0));
	int result = 1 + (rand() % 10);
	result = result % 2;
	return result;
}

BOOL check_if_draw(BOARD game_board, char player_1, char player_2) {
	Board* board = (Board*)game_board;
	char temp;

	for (int i = 1; i <= 9; i++) {
		temp = board->layout[i];
		if (temp != player_1 && temp != player_2) {
			return FALSE; 
		}
		
	}

	return TRUE; 
}

int random_number_generator() {
	int random_number; 
	srand((unsigned int)time(0));
	random_number = 1+ (rand() % 9);


	return random_number; 
}