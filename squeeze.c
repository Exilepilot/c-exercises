/*
 * Filter a c-string.
 * FIXME: Weird ASCII output?
 */
#include <stdio.h>  // getchar, printf
#include <string.h> // strlen, strcpy

#define MAX_SIZE 30

/*
 * Get C-string input
 */
int getln(char p[], char s[], int maxsize)
{
    printf("%s", p);
    
    int i, c;
    for (i = 0; i < maxsize    && 
        (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    return i;
}

/* Empty two strings */
void clear(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        s[i] = 0;
}

/* Printf giving off weird
 * ASCII, lets try if this works.
 */
void printstr(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != 0)
            putchar(s[i]);
    }
    putchar('\n');
}
/*
 * Removes any element of p from s,
 * returns 1 if successful, otherwise 0.
 */
void squeeze(char s[], char p[])
{
    int slen, plen, i, k;
    slen = strlen(s);
    plen = strlen(p);

    /* Check if either are empty */
    if (s != p)
    {
        /* Setup local string for later */
        char str[slen];
       
        /* Has a match been found? */
        int found = 0;
        int j;
        for (i = j = 0; i <= slen; i++)
        {
            for (k = 0; k <= plen; k++)
            {
                if (p[k] == s[i])
                {
                    found = 1;
                    break;
                }
            }
            
            if (!found)
                str[j++] = s[i];
            else
                found = 0;

            printf("\n%s", str);
        }

        strcpy(s, str);
    }
    else
        clear(s);
}

int main(void)
{

    return 0;
}
