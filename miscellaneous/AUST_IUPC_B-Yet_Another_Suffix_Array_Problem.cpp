/**
 * Cefalo CodeFiesta 2022: AUST IUPC
 * Problem B - Yet Another Suffix Array Problem
 * Time: 1.8s
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 100001

long long int per[LIM];

int upper(int n, long long int val)
{
    int b = 1, e = n, mid;

    while(b <= e)
    {
        mid = (b + e) / 2;

        if(val < per[mid])
            e = mid - 1;
        else b = mid + 1;
    }

    return b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC, n, nQueries, pos[LIM], i, el, ub;
    long long int k;
    per[0] = 0;

    cin >> TC;
    
    while(TC--)
    {
        cin >> n >> nQueries;

        for(i = 1; i <= n; ++i)
        {
            cin >> el;
            pos[el] = i;
            per[el] = n - i + 1;
        }

        for(i = 2; i <= n; ++i) per[i] += per[i-1];

        while(nQueries--)
        {
            cin >> k;

            ub = upper(n, k);

            if(per[ub - 1] == k) --ub;

            cout << pos[ub] << ' ' << pos[ub] + k - per[ub - 1] - 1 << '\n';
        }
    }

    return 0;
}
