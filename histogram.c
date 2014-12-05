#include <stdio.h>
#define false 0
#define true 1
#define MAXWORDCOUNT 15

main()
{
    int c, nc, i, j, wcount[MAXWORDCOUNT], wfound;
    for (i = 0; i < MAXWORDCOUNT; ++i)
        wcount[i] = 0;

    nc = 0, wfound = false;
    while ((c=getchar())!= EOF)
    {
        if (c >= 'A' && c <= 'z')
        {
            if (wfound != true)
                wfound = true;
            ++nc;
        }
        else if (wfound == false)
        {
            ++wcount[nc];
            wfound = false, nc = 0;
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
