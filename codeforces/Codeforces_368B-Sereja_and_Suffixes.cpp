/**
* Codeforces Round #215 (Div. 2)
* Porblem B - Sereja and Suffixes
* Time: 296 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <bitset>

using namespace std;

#define LIMIT 100001

int main()
{
    ios_base::sync_with_stdio(false);

    int nElements, nQueries, ara[LIMIT + 1], ans[LIMIT], query;
    bitset <LIMIT> bits;
    register int i;

    cin >> nElements >> nQueries;

    for(i = 1; i <= nElements; ++i)
        cin >> ara[i];

    ara[nElements+1] = 0;
    for(i = nElements; i >= 0; --i)
    {
        ans[i] = ans[i+1];
        if(!bits[ara[i]])
            ++ans[i];

        bits.set(ara[i]);
    }

    while(nQueries--)
    {
        cin >> query;
        cout << ans[query] << '\n';
    }

    return 0;
}
