#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

#include "../include/board.h"
#include "../include/gameTitle.h"
#include "../include/clearScreen.h"
#include "../include/assets.h"

int main(void)
{
    int c;
    int gameLoop = 0;
    int gameMode = 0;
    int gamePlayer = 0;
    
    wchar_t playerX;                    
    wchar_t playerO;                    
    wchar_t board[9] = {
        '0', '1', '2',
        '3', '4', '5', 
        '6', '7', '8'
    };


    /*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    It's necessary because our program will use Unicode Characters (emojis),
    so we must configure the console to be able to display such characters.
    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
    setlocale(LC_ALL, "en_US.utf-8");

    
    /*=-=-=-=-=-=-=
    Main game loop
    =-=-=-=-=-=-=*/
    while (1)
    {
        /*=-=-=-=-=-=-=-=-=
        Input for game mode
        =-=-=-=-=-=-=-=-=*/
        do
        {
            clear_screen();
            game_title();

            printf("%sChoose the game mode:\n", BOLD);
            printf("[ 1 ]  %lc vs %lc\n", PERSON, PERSON);
            printf("[ 2 ]  %lc vs %lc\n", PERSON, COMPUTER);
            printf(">>> %s", RESET);

            scanf("%d", &gameMode);
            while ((c = getchar()) != '\n' && c != EOF);

            if (gameMode != 1 && gameMode != 2)
            {
                printf("%sPlease enter a valid input!%s\n", RED_BOLD, RESET);
                sleep(2);
                continue;
            }

        } while (gameMode != 1 && gameMode != 2);


        /*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        Input for the player's character
        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
        do
        {
            clear_screen();
            game_title();

            printf("%sChoose your sidee:\n", BOLD);
            printf("[ 1 ]  %lc\n", PLAYER_X);
            printf("[ 2 ]  %lc\n", PLAYER_O);
            printf(">>> %s", RESET);

            scanf("%d", &gamePlayer);
            while ((c = getchar()) != '\n' && c != EOF);

            if (gamePlayer != 1 && gamePlayer != 2)
            {
                printf("%sPlease enter a valid input!%s\n", RED_BOLD, RESET);
                sleep(2);
                continue;
            }
            
        } while (gamePlayer != 1 && gamePlayer != 2);

        break;
    }

    return 0;
}
