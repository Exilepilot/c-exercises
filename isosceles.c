/* Exilepilot
 * Write a function that outputs a
 * right isosceles triangle of height
 * and width n.
 */

#include <stdio.h>

/* Get an integer */
int getnum(char s[])
{
    int num;
    printf(s);
    scanf("%d", &num);
    return num;
}

int main(void)
{
    int num = getnum("Enter the width of the triangle: ");
    int i, j;

    for (i = 1; i <= num; ++i)
    {
        for (j = 1; j <= i; ++j)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
