#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

#include "board.h"
#include "assets.h"

int handleInput(void);
void clearScreen(void);
void showErrorMsg(void);
void showGameStatus(wchar_t winner);


int main(void)
{   
    /*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    GAME SETUP
    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
    wchar_t player1;
    wchar_t player2;
    wchar_t winner;
    wchar_t board[9];
    char restartGame;
    
    int player1Pos;
    int player2Pos;
    int round;
    int matches = 0;
    
    setlocale(LC_ALL, "en_US.utf-8");


    /*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // GAME LOOP
    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
    while (1)
    {
        player1 = X;
        player2 = O;
        winner = ' ';
        wchar_t board[9] = {
        '1', '2', '3',
        '4', '5', '6', 
        '7', '8', '9'
        };
        restartGame = 'Y';

        player1Pos = 1;
        player2Pos = 1;
        round = 1;
        matches += 1;

        
        //----------------------------------------------------------------------------------------------------
        // The maximum number of iterations in the loop is 9 rounds, according to the number of positions on the board
        for (round; round <= 9; round++)
        {
            //----------------------------------------------------------------------------------------------------
            // Updates the player's screen
            clearScreen();
            showBoard(board, round, matches);


            //----------------------------------------------------------------------------------------------------
            // Asks the player for an input
            printf("%sEnter a position: ", WHITE_BOLD);
            (round % 2 != 0) ? (player1Pos = handleInput()) : (player2Pos = handleInput());


            //----------------------------------------------------------------------------------------------------
            // Checks if the input is within the allowed values
            if ((player1Pos < 1 || player1Pos > 9) || (player2Pos < 1 || player2Pos > 9))
            {
                showErrorMsg();
                --round;
            }
            
            
            //----------------------------------------------------------------------------------------------------
            // Checks whether the chosen position is free on the board
            else if (((round % 2 != 0) && !(isdigit(board[player1Pos - 1]))) || ((round % 2 == 0) && !(isdigit(board[player2Pos - 1]))))
            {
                showErrorMsg();
                --round;
            }
            
            
            //----------------------------------------------------------------------------------------------------
            // If the entry is correct, place the piece in the chosen position on the board
            else
            {
                if (round % 2 != 0)
                    board[player1Pos - 1] = player1;
                else
                    board[player2Pos - 1] = player2;
            }   


            //----------------------------------------------------------------------------------------------------
            // Checks if there is a victory condition and closes the loop
            if (round >= 5)
            {
                for (int i = 0; i < 9; i++)
                {
                    // Horizontal check
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
                    // Vertical check
                    if (i == 0 || i == 1 || i == 2)
                    {
                        if (board[i] == X && board[i+3] == X && board[i+6] == X)
                        {
                            winner = X;
                        }
                        else if (board[i] == O && board[i+3] == O && board[i+6] == O)
                        {
                            winner = O;
                        }
                    }
                    // Diagonal check
                    if (i == 0 || i == 2)
                    {
                        if (i == 0)
                        {
                            if (board[i] == X && board[i+4] == X && board[i+8] == X)
                            {
                                winner = X;
                            }
                            else if (board[i] == O && board[i+4] == O && board[i+8] == O)
                            {
                                winner = O;
                            }   
                        }
                        else
                        {
                            if (board[i] == X && board[i+2] == X && board[i+4] == X)
                            {
                                winner = X;
                            }
                            else if (board[i] == O && board[i+2] == O && board[i+4] == O)
                            {
                                winner = O;
                            }   
                        }
                    }
                }
            }

            if (winner == X || winner == O)
                break;
        }


        //----------------------------------------------------------------------------------------------------
        // Block that checks if the player wants to play again
        do
        {
            clearScreen();
            showBoard(board, round, matches);
            showGameStatus(winner);

            printf("%s Restart the game? [Y/n] ", WHITE_BOLD);
            scanf(" %c", &restartGame);
            getchar();

            if (toupper(restartGame) != 'Y' && toupper(restartGame) != 'N')
            {
                showErrorMsg();
            }

        } while (toupper(restartGame) != 'Y' && toupper(restartGame) != 'N');


        //----------------------------------------------------------------------------------------------------
        // Leave the game
        if (toupper(restartGame) == 'N')
        {
            break;
        }
    }

    return 0;
}


//----------------------------------------------------------------------------------------------------
// Clear Screen function
void clearScreen(void)
{
    system("clear");
}


//----------------------------------------------------------------------------------------------------
// Function to take the player's input and return only whole numbers
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


//----------------------------------------------------------------------------------------------------
// Function to show the win or draw status on the screen
void showGameStatus(wchar_t winner)
{
    if (winner == X || winner == O)
    {
        printf("%s%lc PLAYER %lc WON THE GAME!%s\n", WHITE_BOLD, TROPHY, winner, RESET);
    }
    else
    {
        printf("%s DRAW!%s\n", WHITE_BOLD, RESET);
    }
    printf("%s _____________________________________%s\n\n",WHITE_BOLD, RESET);
}


//----------------------------------------------------------------------------------------------------
// Function to show error message
void showErrorMsg(void)
{
    printf("%s Enter a valid input!%s\n", RED_BOLD, RESET);
    sleep(1.5);   
}
