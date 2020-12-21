/***Next Task****
* UVA 11057
* Exact Sum
* With Number Theory (Solved without any previous knowledge about this :D )
***/

#include <stdio.h>

int main()
{
    int n, i, j, amount, low, high, temp;

    while(scanf("%d", &n)!=EOF)
    {
        int ara[n];

        for(i = 0; i<n; i++)
            scanf("%d", &ara[i]);

        scanf("%d", &amount);

        for(i = 0; i<n-1; i++)
        {
            for(j = 0; j+i<n-1; j++)
            {
                if(ara[j]>ara[j+1])
                {
                    temp = ara[j];
                    ara[j] = ara[j+1];
                    ara[j+1] = temp;
                }
            }
        }

        for(i = 0; ara[i]<=amount/2;i++)
        {
            for(j = i+1; ara[j]<amount; j++)
            {
                if(ara[i]+ara[j] == amount)
                {
                    low = i;
                    high = j;
                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", ara[low], ara[high]);
    }

    return 0;
}
