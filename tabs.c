#include <stdio.h> // getchar, putchar, printf

#define MAXSIZE 50    // Max amount of elements any string inputted can be.
#define TABTOSPACE 2  // Amount of spaces to tabs.


int line(char s[], int maxsize)
{
    int i, c;
    
    for (i = 0; i < maxsize && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    return i;
}


int main()
{
    char input[MAXSIZE];
    int length, i, j;
    int tabs = 0;

    while ((length = line(input, MAXSIZE)) > 0)
    {
        for (i = 0; i < length; ++i)
        {
            if (input[i] != '\t')
                putchar(input[i]);
            else
            {
                for (j = 0; j < TABTOSPACE; ++j)
                {
                    putchar(' ');
                    ++tabs;
                }
            }
        }

        putchar('\n');
        printf("Tabs found: %d\n", tabs);
    }

    return 0;
}
