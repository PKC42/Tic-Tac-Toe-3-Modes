#include <stdio.h>
#include <stdlib.h>
#include "game_modes.h"



void player_vs_player(BOARD game_board) {
	Board* board = (Board*)game_board; 
	char player_1; 
	char player_2; 
	int returned_val = 1; 
	int placement; 
	BOOL result; 
	BOOL draw_check; 


	printf("Which marker would player 1 like?:");

	do {
		clearKeyboardBuffer();
		returned_val = scanf("%c", &player_1);
		if (returned_val != 1) {
			printf("Please select a valid charactar for a marker!\n");
			clearKeyboardBuffer(); 
		}

	}while (returned_val != 1);


	printf("Which marker would player 2 like?:");

	do {
		clearKeyboardBuffer();
		returned_val = scanf("%c", &player_2);
		if (returned_val != 1) {
			printf("Please select a valid charactar for a marker!\n");
			clearKeyboardBuffer();
		}

		if (player_2 == player_1) {
			printf("Player markers can not be the same. Please choose another marker!\n");
		}

	} while (returned_val != 1 || player_2 == player_1);

	print_board(board);
	
	printf("To decide who goes first a coin will be flipped. Player 1 is assigned to heads and Player 2 is assigned to tails.\n");
	printf("A coin has been flipped!\n");

	if (coin_flip() == 1) {
		printf("The coins is on heads! Player 1 goes first!\n");
		
		while (1) {
	
			printf("Player 1 - Choose a place to put a marker!\n");

			do {
				if (returned_val != 1) {
					clearKeyboardBuffer();
				}
				returned_val = scanf("%d", &placement);
				result = place_marker(board, player_1, player_2, placement); 
			}while (result != SUCCESS);
			print_board(board);
			if (check_winner(board) == TRUE) {
				printf("Player 1 wins!\n");
				return;
			}
			
			draw_check = check_if_draw(board, player_1, player_2);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}
			printf("Player 2 - Choose a place to put a marker!\n");

			do {
				if (returned_val != 1) {
					clearKeyboardBuffer();
				}
				returned_val = scanf("%d", &placement);
				result = place_marker(board, player_2, player_1, placement);
			} while (result != SUCCESS);
			print_board(board);
			if (check_winner(board) == TRUE) {
				printf("Player 2 wins!\n");
				return;
			}
			
			draw_check = check_if_draw(board, player_1, player_2);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}
		}

	}
	else {
		printf("The coin is on tails, Player 2 goes first!\n");

		while (1) {

			printf("Player 2 - Choose a place to put a marker!\n");

			do {
				if (returned_val != 1) {
					clearKeyboardBuffer();
				}
				returned_val = scanf("%d", &placement);
				result = place_marker(board, player_2, player_1, placement);
			} while (result != SUCCESS);
			print_board(board);
			if (check_winner(board) == TRUE) {
				printf("Player 2 wins!\n");
				return;
			}
			
			draw_check = check_if_draw(board, player_1, player_2);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}

			printf("Player 1 - Choose a place to put a marker!\n");

			do {
				if (returned_val != 1) {
					clearKeyboardBuffer();
				}
				returned_val = scanf("%d", &placement);
				result = place_marker(board, player_1, player_2, placement);
			} while (result != SUCCESS);
			print_board(board);
			if (check_winner(board) == TRUE) {
				printf("Player 1 wins!\n");
				return;
			}
			
			draw_check = check_if_draw(board, player_1, player_2);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}
		}
	}
}

void player_vs_computer_easy(BOARD game_board) {
	Board* board = (Board*)game_board;
	int returned_val; 
	char player; 
	char ai; 
	int placement;
	BOOL result;
	BOOL draw_check;

	printf("Which marker would player 1 like?:");

	do {
		clearKeyboardBuffer();
		returned_val = scanf("%c", &player);
		if (returned_val != 1) {
			printf("Please select a valid charactar for a marker!\n");
			clearKeyboardBuffer();
		}

	} while (returned_val != 1);

	if (player == 'X' || player == 'x') {
		ai = 'O';
	}
	else {
		ai = 'X';
	}

	printf("The marker of your opponnent is %c!\n", ai);

	print_board(board);

	printf("To decide who goes first a coin will be flipped. Player 1 is assigned to heads and the computer is assigned to tails.\n");
	printf("A coin has been flipped!\n");

	if (coin_flip() == 1) {
		printf("The coins is on heads! Player goes first!\n");

		while (1) {

			printf("Player - Choose a place to put a marker!\n");

			do {
				if (returned_val != 1) {
					clearKeyboardBuffer();
				}
				returned_val = scanf("%d", &placement);
				result = place_marker(board, player, ai, placement);
			} while (result != SUCCESS);
			print_board(board);
			if (check_winner(board) == TRUE) {
				printf("Player wins!\n");
				return;
			}

			draw_check = check_if_draw(board, player, ai);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}

			printf("\n");

			easy_mode_ai(game_board, player, ai);
			printf("The computer has chosen a spot!\n");
			print_board(board);
			

			if (check_winner(board) == TRUE) {
				printf("Computer wins!\n");
				return;
			}

			draw_check = check_if_draw(board, player, ai);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}
		}

	}
	else {
		printf("The coin is on tails, Computer goes first!\n");

		while (1) {

			printf("\n");

			easy_mode_ai(game_board, player, ai);
			printf("The computer has chosen a spot!\n");
			print_board(board);
			

			if (check_winner(board) == TRUE) {
				printf("Computer wins!\n");
				return;
			}

			draw_check = check_if_draw(board, player, ai);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}

			printf("Player 1 - Choose a place to put a marker!\n");

			do {
				if (returned_val != 1) {
					clearKeyboardBuffer();
				}
				returned_val = scanf("%d", &placement);
				result = place_marker(board, player, ai, placement);
			} while (result != SUCCESS);
			print_board(board);
			if (check_winner(board) == TRUE) {
				printf("Player wins!\n");
				return;
			}

			draw_check = check_if_draw(board, player, ai);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}
		}
	}
}

void player_vs_computer_medium(BOARD game_board) {
	Board* board = (Board*)game_board;
	int returned_val;
	char player;
	char ai;
	int placement;
	BOOL result;
	BOOL draw_check;

	printf("Which marker would player 1 like?:");

	do {
		clearKeyboardBuffer();
		returned_val = scanf("%c", &player);
		if (returned_val != 1) {
			printf("Please select a valid charactar for a marker!\n");
			clearKeyboardBuffer();
		}

	} while (returned_val != 1);

	if (player == 'X' || player == 'x') {
		ai = 'O';
	}
	else {
		ai = 'X';
	}

	printf("The marker of your opponnent is %c!\n", ai);

	print_board(board);

	printf("To decide who goes first a coin will be flipped. Player 1 is assigned to heads and the computer is assigned to tails.\n");
	printf("A coin has been flipped!\n");

	if (coin_flip() == 1) {
		printf("The coins is on heads! Player goes first!\n");

		while (1) {

			printf("Player 1 - Choose a place to put a marker!\n");

			do {
				if (returned_val != 1) {
					clearKeyboardBuffer();
				}
				returned_val = scanf("%d", &placement);
				result = place_marker(board, player, ai, placement);
			} while (result != SUCCESS);
			print_board(board);
			if (check_winner(board) == TRUE) {
				printf("Player wins!\n");
				return;
			}

			draw_check = check_if_draw(board, player, ai);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}

			printf("\n");

			medium_mode_ai(game_board, player, ai);
			printf("The computer has chosen a spot!\n");
			print_board(board);
			

			if (check_winner(board) == TRUE) {
				printf("Computer wins!\n");
				return;
			}

			draw_check = check_if_draw(board, player, ai);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}
		}

	}
	else {
		printf("The coin is on tails, Computer goes first!\n");

		while (1) {

			printf("\n");

			medium_mode_ai(game_board, player, ai);
			printf("The computer has chosen a spot!\n");
			print_board(board);

			if (check_winner(board) == TRUE) {
				printf("Computer wins!\n");
				return;
			}

			draw_check = check_if_draw(board, player, ai);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}

			printf("Player 1 - Choose a place to put a marker!\n");

			do {
				if (returned_val != 1) {
					clearKeyboardBuffer();
				}
				returned_val = scanf("%d", &placement);
				result = place_marker(board, player, ai, placement);
			} while (result != SUCCESS);
			print_board(board);
			if (check_winner(board) == TRUE) {
				printf("Player wins!\n");
				return;
			}

			draw_check = check_if_draw(board, player, ai);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}
		}
	}
}

void player_vs_computer_hard(BOARD game_board) {
	Board* board = (Board*)game_board;
	int returned_val;
	char player;
	char ai;
	int placement;
	BOOL result;
	BOOL draw_check;

	printf("Which marker would player 1 like?:");

	do {
		clearKeyboardBuffer();
		returned_val = scanf("%c", &player);
		if (returned_val != 1) {
			printf("Please select a valid charactar for a marker!\n");
			clearKeyboardBuffer();
		}

	} while (returned_val != 1);

	if (player == 'X' || player == 'x') {
		ai = 'O';
	}
	else {
		ai = 'X';
	}

	printf("The marker of your opponnent is %c!\n", ai);

	print_board(board);

	printf("To decide who goes first a coin will be flipped. Player 1 is assigned to heads and the computer is assigned to tails.\n");
	printf("A coin has been flipped!\n");

	if (coin_flip() == 1) {
		printf("The coins is on heads! Player goes first!\n");

		while (1) {

			printf("Player - Choose a place to put a marker!\n");

			do {
				if (returned_val != 1) {
					clearKeyboardBuffer();
				}
				returned_val = scanf("%d", &placement);
				result = place_marker(board, player, ai, placement);
			} while (result != SUCCESS);
			print_board(board);
			if (check_winner(board) == TRUE) {
				printf("Player wins!\n");
				return;
			}

			draw_check = check_if_draw(board, player, ai);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}

			printf("\n");

			medium_mode_ai(game_board, player, ai);
			printf("The computer has chosen a spot!\n");
			print_board(board);
			

			if (check_winner(board) == TRUE) {
				printf("Computer wins!\n");
				return;
			}

			draw_check = check_if_draw(board, player, ai);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}
		}

	}
	else {
		printf("The coin is on tails, Computer goes first!\n");

		while (1) {

			printf("\n");

			medium_mode_ai(game_board, player, ai);
			printf("The computer has chosen a spot!\n");
			print_board(board);
			

			if (check_winner(board) == TRUE) {
				printf("Computer wins!\n");
				return;
			}

			draw_check = check_if_draw(board, player, ai);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}

			printf("Player 1 - Choose a place to put a marker!\n");

			do {
				if (returned_val != 1) {
					clearKeyboardBuffer();
				}
				returned_val = scanf("%d", &placement);
				result = place_marker(board, player, ai, placement);
			} while (result != SUCCESS);
			print_board(board);
			if (check_winner(board) == TRUE) {
				printf("Player wins!\n");
				return;
			}

			draw_check = check_if_draw(board, player, ai);
			if (draw_check == TRUE) {
				printf("Game ended in a draw!\n");
				return;
			}
		}
	}
}