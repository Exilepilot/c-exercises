#include <stdio.h>

#define MAXWORDCOUNT 15

main()
{
    int c, nc, i, j, wcount[MAXWORDCOUNT], wfound;
    for (i = 0; i < MAXWORDCOUNT; ++i)
        wcount[i] = 0;

    nc = wfound = 0;
    while ((c=getchar())!= EOF)
    {
        if (c >= 'A' && c <= 'z')
        {
            if (wfound != 1)
                wfound = 1;
            ++nc;
        }
        else if (wfound == 1)
        {
            ++wcount[nc];
            wfound = 0;
            nc = 0;
        }
    }

    for (i = 1; i < MAXWORDCOUNT; ++i)
    {
        if (wcount[i] > 0)
        {
            printf("%d: ", i);

            for (j = 0; j < wcount[i]; ++j)
            {
               putchar('*');
            }
            putchar('\n');
        }
    }
}
