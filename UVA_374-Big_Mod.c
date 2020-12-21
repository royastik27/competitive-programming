/**
* UVA 374 - Big Mod
* AUTHOR: Eng. Astik Roy
**/

#include <stdio.h>

int modularExponential(unsigned long long int base, unsigned long long int power, int mod)
{
    unsigned long long int result = 1;

    while(power!=0)
    {
        if(power%2 == 0)
        {
            base = (base*base)%mod;
            power/=2;
        }
        else
        {
            result= (int)((result*base)%mod);
            power--;
        }
    }

    return result;
}

int main()
{
    unsigned long long int base, power;
    int result, mod;

    while(scanf("%llu", &base)!=EOF)
    {
        scanf("%llu %d", &power, &mod);

        result = modularExponential(base, power, mod);

        printf("%d\n", result);
    }

    return 0;
}
