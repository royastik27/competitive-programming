/**
* UVA 11369 - Shopaholic
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

#define LIMIT 20000

int main()
{
    int test, input, ara[LIMIT], i, discount;

    cin >> test;

    while(test--)
    {
        cin >> input;

        for(i = 0; i<input; i++)
            cin >> ara[i];

        sort(ara, ara+input);

        discount = 0;
        for(i = input-3; i>=0; i-=3)
            discount+=ara[i];

        cout << discount << '\n';
    }

    return 0;
}
