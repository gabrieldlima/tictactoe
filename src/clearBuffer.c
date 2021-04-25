#include <stdio.h>

#include "clearBuffer.h"

void clearBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
