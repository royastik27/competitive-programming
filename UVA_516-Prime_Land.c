/**
* UVA 516 - Prime Land
* AUTHOR: Eng. Astik Roy
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int power(int x, int y)
{
    if(y == 1)
        return x;

    return x*power(x, --y);
}

void number_array(char str[], int ara[], int * top)
{
    int i = 0, j;

    ara[0] = 0;
    for(j = 0; str[j]!='\0'; j++)
    {
        if(str[j] == ' ')
        {
            i++;
            ara[i] = 0;
            continue;
        }
        ara[i] = ara[i]*10 + (str[j]-48);
    }
    *top = i;
}

int isprime(int a)
{
    int i;
    if(a == 2)
        return 1;

    for(i = 2; i*i <= a; i++)
    {
        if(a%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[30];
    int ara[20] = {0}, top, i, prev;

    while(1)
    {
        scanf("%[^\n]s", str);

        if(str[0] == '0')
            break;

        top = -1;

        number_array(str, ara, &top);

        prev = 1;
        for(i = 0; i<=top; i+=2)
        {
            prev *= power(ara[i], ara[i+1]);
        }

        prev--;
        top = -1;

        int count;
        for(i = prev; i>=2; i--)
        {
            if(isprime(i))
            {
                count = 0;
                while(prev%i == 0)
                {
                    count++;
                    prev = prev/i;
                }
                if(count == 0)
                    continue;
                ara[++top] = i;
                ara[++top] = count;
            }
        }

        for(i = 0; i<top; i++)
        {
            printf("%d ", ara[i]);
        }
        printf("%d\n", ara[top]);

        getchar();
    }


    return 0;
}
