#include <stdio.h>
#include "medium_mode.h"


void medium_mode_ai(BOARD* game_board, char player, char ai) {
	Board* board = (Board*)game_board;
	int placement;
	STATUS status_check;


	if (board->layout[1] == player && board->layout[2] == player) {
		if (board->layout[3] != player && board->layout[3] != ai) {
			placement = board->layout[3] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[1] == player && board->layout[3] == player) {
		if (board->layout[2] != player && board->layout[2] != ai) {
			placement = board->layout[2] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[2] == player && board->layout[3] == player) {
		if (board->layout[1] != player && board->layout[1] != ai) {
			placement = board->layout[1] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	//**************************************************************************************************

	if (board->layout[4] == player && board->layout[5] == player) {
		if (board->layout[6] != player && board->layout[6] != ai) {
			placement = board->layout[6] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[4] == player && board->layout[6] == player) {
		if (board->layout[5] != player && board->layout[5] != ai) {
			placement = board->layout[5] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[5] == player && board->layout[6] == player) {
		if (board->layout[4] != player && board->layout[4] != ai) {
			placement = board->layout[4] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	//**************************************************************************************************

	if (board->layout[7] == player && board->layout[8] == player) {
		if (board->layout[9] != player && board->layout[9] != ai) {
			placement = board->layout[9] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[7] == player && board->layout[9] == player) {
		if (board->layout[8] != player && board->layout[8] != ai) {
			placement = board->layout[8] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[8] == player && board->layout[9] == player) {
		if (board->layout[7] != player && board->layout[7] != ai) {
			placement = board->layout[7] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	//**************************************************************************************************

	if (board->layout[1] == player && board->layout[4] == player) {
		if (board->layout[7] != player && board->layout[7] != ai) {
			placement = board->layout[7] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[1] == player && board->layout[7] == player) {
		if (board->layout[4] != player && board->layout[4] != ai) {
			placement = board->layout[4] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[4] == player && board->layout[7] == player) {
		if (board->layout[1] != player && board->layout[1] != ai) {
			placement = board->layout[1] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	//**************************************************************************************************

	if (board->layout[2] == player && board->layout[5] == player) {
		if (board->layout[8] != player && board->layout[8] != ai) {
			placement = board->layout[8] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[2] == player && board->layout[8] == player) {
		if (board->layout[5] != player && board->layout[5] != ai) {
			placement = board->layout[5] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[5] == player && board->layout[8] == player) {
		if (board->layout[2] != player && board->layout[2] != ai) {
			placement = board->layout[2] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	//**************************************************************************************************

	if (board->layout[3] == player && board->layout[6] == player) {
		if (board->layout[9] != player && board->layout[9] != ai) {
			placement = board->layout[9] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[3] == player && board->layout[9] == player) {
		if (board->layout[6] != player && board->layout[6] != ai) {
			placement = board->layout[6] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[6] == player && board->layout[9] == player) {
		if (board->layout[3] != player && board->layout[3] != ai) {
			placement = board->layout[3] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	//**************************************************************************************************

	if (board->layout[1] == player && board->layout[5] == player) {
		if (board->layout[9] != player && board->layout[9] != ai) {
			placement = board->layout[9] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[1] == player && board->layout[9] == player) {
		if (board->layout[5] != player && board->layout[5] != ai) {
			placement = board->layout[5] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[5] == player && board->layout[9] == player) {
		if (board->layout[1] != player && board->layout[1] != ai) {
			placement = board->layout[1] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	//**************************************************************************************************
	if (board->layout[3] == player && board->layout[5] == player) {
		if (board->layout[7] != player && board->layout[7] != ai) {
			placement = board->layout[7] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[3] == player && board->layout[7] == player) {
		if (board->layout[5] != player && board->layout[5] != ai) {
			placement = board->layout[5] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	if (board->layout[5] == player && board->layout[7] == player) {
		if (board->layout[3] != player && board->layout[3] != ai) {
			placement = board->layout[3] - '0';
			place_marker_ai(board, ai, player, placement);
			return;
		}
	}

	do {
		placement = random_number_generator();
		status_check = place_marker_ai(game_board, ai, player, placement);
	} while (status_check == FALSE);

}