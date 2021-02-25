/**
* UVA 10940 - Throwing Cards Away 2
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

#define LIMIT 500000

using namespace std;

int main()
{
    int ara[LIMIT+1], i, power2 = 1, add;

    for(i = 1; i<=LIMIT; i++)
    {
        if(i == power2)
        {
            ara[i] = i;
            power2*=2;
            add = 2;
        }
        else
        {
            ara[i] = add;
            add+=2;
        }
    }

    while(cin >> add)
    {
        if(!add) break;

        cout << ara[add] << '\n';
    }

    return 0;
}
