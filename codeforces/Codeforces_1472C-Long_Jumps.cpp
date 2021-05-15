/**
* Codeforces Round #693 (Div. 3)
* Problem C - Long Jumps
* Time: 108 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 200000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, len, ara[LIMIT], idx, Max;
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> len;

        for(i = 0; i < len; ++i)
            cin >> ara[i];

        Max = ara[len - 1];

        for(i = len-2; i >=0; --i)
        {
            idx = ara[i] + i;

            if(idx < len)
                ara[i] += ara[idx];

            if(ara[i] > Max)
                Max = ara[i];
        }

        cout << Max << '\n';
    }

    return 0;
}
