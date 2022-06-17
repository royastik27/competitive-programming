/**
 * Educational Codeforces Round 129 (Rated for Div. 2)
 * Problem C - Double Sort
 * URL: https://codeforces.com/problemset/problem/1681/C
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;

#define LIM 101

bool checkBit(int n, int pos)
{
    return n & (1 << pos);
}

void setBit(int * n, int pos) { *n |= (1 << pos); }

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int a[LIM], sortedA[LIM], b[LIM], sortedB[LIM], TC, n, i, pos[LIM];
    bool impossible;

    cin >> TC;

    while(TC--)
    {
        cin >> n;

        memset(pos, 0, (n+1)*sizeof(int));

        for(i = 1; i <= n; ++i)
        {
            cin >> a[i];
            sortedA[i] = a[i];
            setBit(&pos[a[i]], i);
        }

        for(i = 1; i <= n; ++i)
        {
            cin >> b[i];
            sortedB[i] = b[i];
            setBit(&pos[b[i]], i);
        }

        // SORTING
        sort(sortedA, sortedA+n+1);
        sort(sortedB, sortedAB+n+1);

        // MAIN OPERATION
        impossible = false;
        for(i = 1; i <= n; ++i)
        {
            //
        }

        // cout << "positions:\n";
        // for(i = 1; i <= n; ++i)
        // {
        //     cout << i << ": ";
        //     for(int j = 1; j <= n; ++j)
        //     {
        //         if(checkBit(pos[i], j)) cout << j << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    return 0;
}
