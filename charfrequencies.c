/*
 *  Get input, then print a histogram of the frequencies of each
 *  character that has been input.
 */

#include <stdio.h>
#define LIMIT 52 // Two sets of characters (Capital/non capital)

int main()
{
    int c, characters[LIMIT], i;

    for (i = 0; i < LIMIT; ++i)
        characters[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= 'A' && c <= 'z')
        {
            ++characters[c - 'A'];
        }
    }

    for (i = 0; i < LIMIT; ++i)
    {
        if (characters[i] > 0)
        {
            putchar(i + 'A');
            printf(": ");

            int j;
            for (j = 0; j < characters[i]; ++j)
                putchar('*');

            putchar('\n');

        }
   }
}
