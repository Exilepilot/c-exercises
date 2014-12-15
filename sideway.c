#include <stdio.h>

/* Get an integer */
int getnum(char s[])
{
    int num;
    printf(s);
    scanf("%d", &num);
    return num;
}


void sideway_triangle(int num)
{
    int i, j;

    for(i = 0; i < num; ++i)
    {
        for (j = 1; j <= i; ++j)
            putchar('*');
        putchar('\n');
    }

    for (i = num - 1; i >= 0; --i)
    {
        for (j = 0; j <= i; ++j)
            putchar('*');
        putchar('\n');
    }
}

int main(void)
{
    int num = getnum("Enter the width of the triangle: ");
    sideway_triangle(num);
    return 0;
}

