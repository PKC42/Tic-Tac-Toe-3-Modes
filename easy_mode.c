#include "easy_mode.h"
#include "basic.h"
#include <stdio.h>
#include <stdlib.h>

void easy_mode_ai(BOARD* game_board, char player, char ai) {
	Board* board = (Board*)game_board; 
	STATUS status_check; 
	int placement; 
	
	do {
		placement = random_number_generator(); 
		status_check = place_marker_ai(game_board, ai, player, placement);
	} while (status_check == FALSE);

}




