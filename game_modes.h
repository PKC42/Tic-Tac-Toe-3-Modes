#ifndef GAME_MODES_h
#define GAME_MODES_h
#include "basic.h"
#include "status.h"
#include "easy_mode.h"
#include "medium_mode.h"
#include "hard_mode.h"

void player_vs_player(BOARD game_board);

void player_vs_computer_easy(BOARD game_board);

void player_vs_computer_medium(BOARD game_board);

void player_vs_computer_hard(BOARD game_board);


#endif
