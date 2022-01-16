#include <stdio.h>
#include <ctype.h>
#include "basic.h"
#include "game_modes.h"

int main(int argc, const char* argv[])
{
    BOARD* board;
    printf("Welcome to tic-tac-toe. ");
    char choice = 'n';
    int game_mode;
    int difficulty;
    int returned_val;

    do {
        board = init_board();
        do {

            printf("Which mode would you like to play?\n");
            printf("1. Player 1 vs Player 2 (Press 1)\n");
            printf("2. Player 2 vs Computer (Press 2) \n");
            printf("3. Exit (Press 3)\n");

            returned_val = scanf("%d", &game_mode);
            if (returned_val != 1 || game_mode > 3 || game_mode < 1) {
                printf("Please enter a valid game mode!\n");
                clearKeyboardBuffer();
            }
        } while (returned_val != 1 || game_mode > 3 || game_mode < 1);

        if (game_mode == 1) {
            player_vs_player(board);
        }
        else if (game_mode == 2) {
            printf("Which level of difficulty do you choose?\n");
            printf("1. Easy (Press 1)\n");
            printf("2. Medium (Press 2)\n");
            printf("3. Hard (Press 3)\n");
            printf("4. End program (Press 4\n");
            returned_val = scanf("%d", &difficulty);
            if (returned_val != 1 || difficulty > 4 || difficulty < 1) {
                printf("Please enter a valid game mode!\n");
                clearKeyboardBuffer();
            }

            if (difficulty == 1) {
                player_vs_computer_easy(board);
            }

            if (difficulty == 2) {
                player_vs_computer_medium(board);
            }

            if (difficulty == 3) {
                player_vs_computer_hard(board);
            }

            if (difficulty == 4) {
                destroy_board(board);
                return 0;
            }
        }
        else if (game_mode == 3) {
            destroy_board(board);
            return 0;

        }
        destroy_board(board);

        printf("Would you like to play again?\n");

        do {
            clearKeyboardBuffer();
            printf("Press y for yes and n for no.: ");
            returned_val = scanf("%c", &choice);
        } while (returned_val != 1 || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N'));

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
