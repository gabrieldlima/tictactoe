#include <stdio.h>

#include "../include/gameTitle.h"
#include "../include/assets.h"

void game_title(void)
{
    for (int i = 0; i <= 102; ++i)
    {
        if (i < 51)
        {
            printf("%lc", BLACK_SQUARE);
        }
        else if (i == 51)
        {
            putchar('\n');
            printf("\t\t\t\t\t%s%lc TIC TAC TOE %lc  %s", ORANGE_BOLD, ORANGE_STAR, ORANGE_STAR, RESET);
            putchar('\n');
        }
        else if (i > 51)
        {
            printf("%lc", WHITE_SQUARE);    
        }
    }
    putchar('\n');
}
