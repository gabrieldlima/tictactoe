#include <stdio.h>
#include <ctype.h>

#include "../include/handleInput.h"

int handleInput(void)
{
    int c;
    int n = 0;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (isdigit(c))
        {
            if (c == '1' || c == '2')
            {
                n = 10 * n + (c - '0');
            }
        }
    }
            
    return n;
}
