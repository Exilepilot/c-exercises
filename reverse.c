#include <stdio.h>
#define MAXSIZE 50 // define the maximum size of a string

/* 
 * get input and the length of the input given
 */

int getLine(char s[],int len)
{
    int c, i;

    for (i = 0; i < len-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    return i;
}

/*
 * Iterate through the string and print the elements.
 */
void printString(char s[], int size)
{
    int i;

    for (i = 0; i <= size; ++i)
        putchar(s[i]);

    putchar('\n');
}

/*
 *  Reverse the string
 */
void reverse(char s[], int size)
{
    int i, j = 0;
    char r[size];
    
    // Copy each element from the far right
    // into the far left of a temporary array
    for (i = size - 1; i >= 0; --i)
    {
        r[j] = s[i];
        ++j;
    }
    
    r[size] = '\0';
    
    for (i = 0; i < size; ++i)
        s[i] = r[i];
}

int main()
{
    int len;
    char line[MAXSIZE];
    
    // Get the actual length of the string then
    // reverse and print the result.
    while ((len = getLine(line, MAXSIZE)) > 0)
    {
        reverse(line, len);
        printString(line, len);
    }
    return 0;
}
