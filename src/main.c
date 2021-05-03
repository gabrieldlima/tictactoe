#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

#include "assets.h"
#include "board.h"

#define TRUE  1
#define FALSE 0

int handleInput(void);
void clearScreen(void);

int main(void)
{   
    /*=-=-=-=-=-
    GAME SETUP()
    =-=-=-=-=-*/
    wchar_t player1;
    wchar_t player2;
    wchar_t board[9];
    wchar_t winner;
    
    int player1Pos;
    int player2Pos;
    int validPos;
    
    setlocale(LC_ALL, "en_US.utf-8");


    /*=-=-=-=-=
    GAME LOOP()
    =-=-=-=-=*/
    while (1)
    {
        player1 = X;
        player2 = O;
        player1Pos = 1;
        player2Pos = 1;
        wchar_t board[9] = {
        '1', '2', '3',
        '4', '5', '6', 
        '7', '8', '9'
        };

        // The maximum number of iterations in the loop is 9 rounds, according to the number of positions on the board
        for (int round = 1; round <= 9; ++round)
        {
            // Updates the player's screen
            clearScreen();
            showBoard(board);

            // Asks the player for an input
            printf("%sEnter a position %lc\n»»» ", BOLD, (round % 2 != 0) ? X : O);
            (round % 2 != 0) ? (player1Pos = handleInput()) : (player2Pos = handleInput());

            // Checks if the input is within the allowed values
            if ((player1Pos < 1 || player1Pos > 9) || (player2Pos < 1 || player2Pos > 9))
            {
                printf("%sEnter a valid input!%s\n", RED_BOLD, RESET);
                sleep(1.5);
                --round;
            }
            // Checks whether the chosen position is free on the board
            else if (((round % 2 != 0) && !(isdigit(board[player1Pos - 1]))) || ((round % 2 == 0) && !(isdigit(board[player2Pos - 1]))))
            {
                printf("%sEnter a valid input!%s\n", RED_BOLD, RESET);
                sleep(1.5);
                --round;
            }
            // If the entry is correct, place the piece in the chosen position on the board
            else
            {
                if (round % 2 != 0)
                    board[player1Pos - 1] = player1;
                else
                    board[player2Pos - 1] = player2;
            }   

            // Checks if there is a victory condition and closes the loop
            // 0 1 2 3 4 5 6 7 8 
            
            int sum = 0;
            for (int i = 0; i < 9; i++)
            {
                if (i == 0 || i == 3 || i == 6)
                {
                    if (board[i] == X && board[i+1] == X && board[i+2] == X)
                    {
                        winner = X;
                    }
                    else if (board[i] == O && board[i+1] == O && board[i+2] == O)
                    {
                        winner = O;
                    }
                    
                }
            }

            if (winner == X)
            {
                clearScreen();
                showBoard(board);
                printf("WINNER %lc\n", X);
                sleep(5);
                break;  
            }
            else if (winner == O)
            {
                clearScreen();
                showBoard(board);
                printf("WINNER %lc\n", O);
                sleep(5);
                break;  
            }
            
        }
        break;
    }

    return 0;
}


void clearScreen(void)
{
    system("clear");
}

int handleInput(void)
{
    int c;
    int n = 0;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (isdigit(c))
        {
            n = 10 * n + (c - '0');
        }
    }
            
    return n;
}
