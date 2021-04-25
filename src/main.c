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
void clearBuffer(void);

int main(void)
{   
    /*=-=-=-=-=-
    GAME SETUP()
    =-=-=-=-=-*/
    wchar_t player1;
    wchar_t player2;
    wchar_t board[9];
    
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
        wchar_t board[9] = {
        '1', '2', '3',
        '4', '5', '6', 
        '7', '8', '9'
        };
    }
}


void clearScreen(void)
{
    system("clear");
}

void clearBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
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
