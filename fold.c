/*
 * Get user input, and fold into seperate lines
 * if string is to big.
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define FOLD 80 // What divisor to fold at.


/*
 * line(char s[], int maxsize)
 * assign input to char array and
 * return it's length.
 */

int line(char s[], int maxsize)
{
    int i, c; 

    for (i = 0; i < maxsize &&
        (c = getchar()) != EOF && c != '\n'; ++i)
      s[i] = c;
    
    return i;
}

/* printstring(char s[], int length, int fold)
 * Print array, folding output at a specific
 * length. If string not big enough then 
 * print the array out.
 */

void printstring(char s[], int length, int fold)
{
    int i;

    if (length > (fold - 1))
    {
        for (i = 0; i < length; ++i)
        {
            if (i % (fold - 1) == 0)
                putchar('\n');

            putchar(s[i]);
        }

        return;
    }

    printf("%s", s);
}

int main(int argc, char *argv[])
{
    char str[BUFFER_SIZE];
    int length;

    while ((length = line(str, BUFFER_SIZE)) > 0)
        printstring(str, length, FOLD);
    return 0;
}
