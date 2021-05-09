#include <stdio.h>
#include <wchar.h>

#include "board.h"
#include "assets.h"

void showBoard(wchar_t array[], int round, int match)
{
    printf("%s=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n", GREEN_BOLD);
    printf("              TIC TAC TOE              \n"            );
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%s\n", RESET     );

    printf("%s\n ", BOLD);
    (array[0] == '1') ? printf(" %lc  |", array[0]) : printf(" %lc |", array[0]);
    (array[1] == '2') ? printf(" %lc  |", array[1]) : printf(" %lc |", array[1]);
    (array[2] == '3') ? printf(" %lc   ", array[2]) : printf(" %lc  ", array[2]);
    printf("\t Player: %lc", (round % 2 != 0) ? X : O);
    printf("\n ----|----|----\n ");
    (array[3] == '4') ? printf(" %lc  |", array[3]) : printf(" %lc |", array[3]);
    (array[4] == '5') ? printf(" %lc  |", array[4]) : printf(" %lc |", array[4]);
    (array[5] == '6') ? printf(" %lc   ", array[5]) : printf(" %lc  ", array[5]);
    printf("\t Round: %3d", round);
    printf("\n ----|----|----\n ");
    (array[6] == '7') ? printf(" %lc  |", array[6]) : printf(" %lc |", array[6]);
    (array[7] == '8') ? printf(" %lc  |", array[7]) : printf(" %lc |", array[7]);
    (array[8] == '9') ? printf(" %lc   ", array[8]) : printf(" %lc  ", array[8]);
    printf("\t Matches: %d", match);

    printf("\n_____________________________________");
    printf("%s\n\n", RESET);
}
