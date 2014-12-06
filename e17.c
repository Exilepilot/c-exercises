/* Exercise 1-17
 *  Write a program to print all input lines that
 *  are longer than 80 characters.
*/

#include <stdio.h>
#define MAXSIZE 120

int getLine(char s[], int ms)
{
    int i, c;
    for (i = 0; i < ms && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    return i;
}


int main(void)
{
    char str[MAXSIZE];
    int len;
    while ((len = getLine(str, MAXSIZE)) > 80)
    {
        int i;
        for (i = 0; i < len; ++i)
            putchar(str[i]);

        putchar('\n');
    }

    return 0;
}
