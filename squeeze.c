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
int squeeze(char s[], char p[])
{
    int slen, plen, i, k;
    
    /* Get length of both */
    slen = strlen(s);
    plen = strlen(p);
    
    /* Check if either are empty */
    if ((slen > 0 && plen > 0) &&
       !(s == p))
    {
        /* Setup local string for later */
        char str[slen];
       
        /* Has a match been found? */
        int found = 0;
        int j;
        for (i = j = 0; i < slen; i++)
        {
            for (k = 0; k < plen; k++)
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
        }

        strcpy(s, str);
    }
    else if (s == p)
    {
        clear(s);
    }
    else
        /* Unsuccessful */
        return 0;

    return 1;
}


int main(void)
{
    int result;
    int len1, len2;
    char str1[MAX_SIZE], str2[MAX_SIZE];
    
    while ((len1 = getln("Enter initial string: ", str1, MAX_SIZE)) > 0)
    {
        len2 = getln("Enter filter string: ", str2, MAX_SIZE);
        result = squeeze(str1, str2);

        if (result)
        {
            printf("Result: ");
            printstr(str1);
        }
        else
            printstr("Try again...");
        /* 
         * Clear both string,
         * Note to self: Nice mess..
         */
        clear(str1);
        clear(str2);
    }

    return 0;
}
