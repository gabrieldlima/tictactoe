#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

#include "../include/board.h"
#include "../include/gameTitle.h"
#include "../include/clearScreen.h"
#include "../include/handleInput.h"
#include "../include/assets.h"

int main(void)
{   
    int isRunning = 1;
    int gameMode = 1;
    int gamePlayer = 1;

    wchar_t X;                    
    wchar_t O;                    
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
    while (isRunning)
    {
        /*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        This block makes the game mode selection routine
        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
        do
        {
            clear_screen();
            game_title();
            
            if (gameMode != 1 && gameMode != 2)
                printf("%sPlease, enter a valid input!%s\n", RED_BOLD, RESET);

            printf("%sChoose the game mode:\n", BOLD);
            printf("[ 1 ] --- %lc vs %lc\n", PERSON, PERSON);
            printf("[ 2 ] --- %lc vs %lc\n", PERSON, COMPUTER);
            printf(">>> ");
            gameMode = handleInput();
            
        } while (gameMode != 1 && gameMode != 2);


        /*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        This block makes the character selection routine
        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
        do
        {
            clear_screen();
            game_title();

            if (gamePlayer != 1 && gamePlayer != 2)
                printf("%sPlease, enter a valid input!%s\n", RED_BOLD, RESET);

            printf("%sChoose your side:\n", BOLD);
            printf("[ 1 ] --- %lc\n", PLAYER_X);
            printf("[ 2 ] --- %lc\n", PLAYER_O);
            printf(">>> ");
            gamePlayer = handleInput();
            
        } while (gamePlayer != 1 && gamePlayer != 2);   
    }

    return 0;
}