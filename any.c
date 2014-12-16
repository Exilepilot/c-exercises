#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20

int getln(char s[], int maxlen)
{
    int i, c;
    for(i = 0; i < maxlen && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    return i;
}

int any(char s[], char p[])
{
    int i, k, location;

    for (i = 0; s[i] != '\0'; i++)
        for (k = 0; p[k] != '\0'; k++)
            if (s[i] == p[k])
                return i;

    return -1;
}

int main(void)
{
    char str[MAX_SIZE], p[MAX_SIZE];
    int location;
    while (getln(str, MAX_SIZE) > 0)
    {
        if (getln(p, MAX_SIZE) > 0)
        {
            printf("Location: %d\n", any(str, p));
        }
    }
}
