#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

#include "board.h"
#include "clearScreen.h"
#include "handleInput.h"
#include "clearBuffer.h"
#include "assets.h"

#define TRUE  1
#define FALSE 0

int main(void)
{   
    int isRunning = 1;
    int gameMode;
    int characterMode;
    int validPosition;

    int player1Pos;
    int player2Pos;
    
    wchar_t player1;
    wchar_t player2;
    wchar_t computer;              
    wchar_t board[9];


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
        wchar_t board[9] = {
        '1', '2', '3',
        '4', '5', '6', 
        '7', '8', '9'
        };
        gameMode = 1;
        characterMode = 1;
        /*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
        This block makes the game mode selection menu
        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
        do
        {
            clear_screen();
            
            if (gameMode != 1 && gameMode != 2)
                printf("%sPlease, enter a valid input!%s\n", RED_BOLD, RESET);

            printf("%sChoose the game mode:\n", BOLD);
            printf("[ 1 ] --- %lc vs %lc\n", PERSON, PERSON);        
            printf("[ 2 ] --- %lc vs %lc\n", PERSON, COMPUTER);
            printf(">>>%s ", RESET);
            gameMode = handleInput();
            
        } while (gameMode != 1 && gameMode != 2);


        /*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
        This block makes the character selection menu
        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
        do
        {
            clear_screen();

            if (characterMode != 1 && characterMode != 2)
                printf("%sPlease, enter a valid input!%s\n", RED_BOLD, RESET);

            printf("%sChoose your side:\n", BOLD);
            printf("[ 1 ] --- %lc\n", X);                                   
            printf("[ 2 ] --- %lc\n", O);                                   
            printf(">>>%s ", RESET);
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


        /*=-=-=-=-=-=-=-=-=-=-
        PLAYER vs PLAYER LOGIC
        =-=-=-=-=-=-=-=-=-=-*/
        if (gameMode == 1)
        {
            for (int round = 0; round < 9; round++)
            {                
                player1Pos = 1;
                player2Pos = 1;
                validPosition = FALSE;

                if (round % 2 == 0)
                {
                    while (validPosition == FALSE)
                    {
                        clear_screen();
                        show_board(board);
                        
                        if (player1Pos < 1 || player1Pos > 9)
                            printf("%sPlease, enter a valid input!%s\n", RED_BOLD, RESET);
                        
                        printf("%sEnter a position%s %lc: ", BOLD, RESET, player1);
                        player1Pos = handleInput();

                        if (player1Pos < 1 || player1Pos > 9)
                            continue;

                        if (isdigit(board[player1Pos-1]))
                        {
                            validPosition = TRUE;
                            board[player1Pos-1] = player1;
                        }
                        else
                        {
                            validPosition = FALSE;
                        }
                    }
                }
                else
                {
                    while (validPosition == FALSE)
                    {
                        clear_screen();
                        show_board(board);
                        
                        if (player2Pos < 1 || player2Pos > 9)
                            printf("%sPlease, enter a valid input!%s\n", RED_BOLD, RESET);
                        
                        printf("%sEnter a position%s %lc: ", BOLD, RESET, player2);
                        player2Pos = handleInput();

                        if (player2Pos < 1 || player2Pos > 9)
                            continue;

                        if (isdigit(board[player2Pos-1]))
                        {
                            validPosition = TRUE;
                            board[player2Pos-1] = player2;
                        }
                        else
                        {
                            validPosition = FALSE;
                        }
                    }
                }

                /*=-=-=-=-=-=-=-=-=-=-=-
                Checks victory condition
                =-=-=-=-=-=-=-=-=-=-=-*/
            } 
        }    
    }
        /*=-=-=-=-=-=-=-=-=-=-=-
        PLAYER vs COMPUTER LOGIC
        =-=-=-=-=-=-=-=-=-=-=-*/
}
