#include <stdio.h>
#include <string.h>
#include <math.h>


/* MAX STRING SIZE */
#define MAX_SIZE 50


/* Get a line of input */
int getline(char s[], int size)
{
    int i, c;
    printf("Please input a hexadecimal (with prefix '0x'): ");
    for (i = 0; i <= size && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    return i;
}

/* Convert a hexadecimal character
 * into it's integer value.
 * Returns -1 if not a valid
 * hex char.
 */
int gethex(char s)
{
    if (s >= '0' && s <= '9')
        return s - '0';
    else if (s >= 'A' && s <= 'F')
        return s - 'A' + 10;
    else if (s >= 'a' && s <= 'f')
        return s - 'a' + 10;
    else
        return -1;
}

/* Does the string contain a prefix? */
int contains_prefix(char s[])
{
    return (s[0] == '0' && (s[1] == 'X' || s[1] == 'x'));
}

/* Hexadecimal to integer */
int htoi(char s[], int length)
{
    int i, j, num, result;

    /* Check for a prefix */
    if (contains_prefix(s))
    {
        j = length - 3;
        result = 0;

        /*
         * Completely ignore the prefix
         * and calculate
         */
        for (i = 2; i <= length - 1; ++i)
        {
            num = gethex(s[i]);
            /* valid character? */
            if (num == -1)
                return -1;

            result += num * pow(16, j--);
        }

        return result;
    }

    return -2;
}

int main(void)
{
    char str[MAX_SIZE];
    int length, result;

    while ((length = getline(str, MAX_SIZE)) >= 2)
    {
        result = htoi(str, length);
        if (result == -1)
            printf("Invalid hex character found.\n");
        else if (result == -2)
            printf("Invalid or no prefix found.\n");
        else
            printf("Result: %d\n", result);
    }

    if (length <= 2)
        printf("Invalid length.\n");

    return 0;
}

