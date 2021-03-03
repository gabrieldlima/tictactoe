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
    int characterMode = 1;
    
    wchar_t player1;
    wchar_t player2;
    wchar_t computer;              
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
        /*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
        This block makes the game mode selection menu
        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
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


        /*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
        This block makes the character selection menu
        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
        do
        {
            clear_screen();
            game_title();

            if (characterMode != 1 && characterMode != 2)
                printf("%sPlease, enter a valid input!%s\n", RED_BOLD, RESET);

            printf("%sChoose your side:\n", BOLD);
            printf("[ 1 ] --- %lc\n", X);
            printf("[ 2 ] --- %lc\n", O);
            printf(">>> ");
            characterMode = handleInput();

        } while (characterMode != 1 && characterMode != 2);   


        /*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
        Set up the players and computer variables
        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
        switch (characterMode)
        {
            case 1:
                player1 = X;

                if (gameMode == 1)
                    player2 = O;
                else
                    computer = O;
                
                break;
            
            case 2:
                player1 = O;

                if (gameMode == 1)
                    player2 = X;
                else
                    computer = X;
                
                break;

            default:
                break;
        }


        /*=-=-=-=-=-=-=-=-=-=-=
        Start of the game logic
        =-=-=-=-=-=-=-=-=-=-=*/
        



    }

    return 0;
}