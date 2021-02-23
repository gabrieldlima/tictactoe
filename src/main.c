#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#include "../include/board.h"
#include "../include/assets.h"

int main(void)
{
    wchar_t playerX = PLAYER_X;
    wchar_t playerO = PLAYER_O;
    wchar_t board[9] = {
        '1', '2', '3',
        '4', '5', '6', 
        '7', '8', '9'
    };

    setlocale(LC_ALL, "en_US.utf-8");
    
    show_board(board);
    
    return 0;
}
