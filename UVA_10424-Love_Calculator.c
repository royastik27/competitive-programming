/**
* UVA 10424 - Love Calculator
* AUTHOR: Eng. Astik Roy
**/

#include <stdio.h>

int getNum(char str[])
{
    int i, sum = 0;

    for(i = 0; str[i] != '\0'; ++i)
    {
        /* making all characters uppercase */
        if(str[i] > 90) str[i] -= 32;

        /* filtering only alphabets */
        if(str[i] >= 65)
            sum += (int)str[i] - 64;
    }

    return sum;
}

int makeOneDigit(int n)
{
    if(n < 10)
        return n;

    return makeOneDigit(n/10 + n%10);
}

int main()
{
    char name1[26], name2[26];
    int i, num1, num2;
    double res;

    while(gets(name1))
    {
        gets(name2);

        num1 = makeOneDigit(getNum(name1));
        num2 = makeOneDigit(getNum(name2));

        if(num1 < num2)
            res = (double)num1/num2 * 100;
        else    res = (double)num2/num1 * 100;

        printf("%0.2lf %%\n", res);
    }

    return 0;
}
