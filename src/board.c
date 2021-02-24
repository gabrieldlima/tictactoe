#include <stdio.h>
#include <wchar.h>

#include "../include/board.h"
#include "../include/assets.h"

void show_board(wchar_t array[])
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

    printf("%s\n", BOLD);

    printf("\t\t\t\t\t");
    (array[0] == '1') ? printf(" %lc  |", array[0]) : printf(" %lc |", array[0]);
    (array[1] == '2') ? printf(" %lc  |", array[1]) : printf(" %lc |", array[1]);
    (array[2] == '3') ? printf(" %lc  ", array[2]) : printf(" %lc ", array[2]);
    printf("\n\t\t\t\t\t----|----|----\n");
    printf("\t\t\t\t\t");
    (array[3] == '4') ? printf(" %lc  |", array[3]) : printf(" %lc |", array[3]);
    (array[4] == '5') ? printf(" %lc  |", array[4]) : printf(" %lc |", array[4]);
    (array[5] == '6') ? printf(" %lc  ", array[5]) : printf(" %lc ", array[5]);
    printf("\n\t\t\t\t\t----|----|----\n");
    printf("\t\t\t\t\t");
    (array[6] == '7') ? printf(" %lc  |", array[6]) : printf(" %lc |", array[6]);
    (array[7] == '8') ? printf(" %lc  |", array[7]) : printf(" %lc |", array[7]);
    (array[8] == '9') ? printf(" %lc  ", array[8]) : printf(" %lc ", array[8]);

    printf("%s\n", RESET);
}
