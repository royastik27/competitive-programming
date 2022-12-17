/**
 * Codeforces Round #179 (Div. 1)
 * Problem A - Greg and Array
 * TIME: 187 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 100001

typedef long long int ll;

class Solution
{
    ll freq[LIM + 1], d[LIM];
    int arr[LIM], left[LIM], right[LIM], n, m, k, i, beg, end;
public:
    void solve()
    {
        cin >> n >> m >> k;

        for(i = 1; i <= n; ++i)
            cin >> arr[i];

        // operations
        for(i = 1; i <= m; ++i)
            cin >> left[i] >> right[i] >> d[i];

        // queries
        memset(freq, 0, (m+2)*sizeof(ll));

        while(k--)
        {
            cin >> beg >> end;

            ++freq[beg];
            --freq[end+1];
        }

        // modifying operation values
        for(i = 2; i <= m; ++i)
            freq[i] += freq[i-1];

        for(i = 1; i <= m; ++i)
            d[i] *= freq[i];

        // processing operations
        memset(freq, 0, (n+2)*sizeof(ll));

        for(i = 1; i <= m; ++i)
        {
            freq[left[i]] += d[i];
            freq[right[i] + 1] -= d[i];
        }

        for(i = 2; i <= n; ++i)
            freq[i] += freq[i-1];

        for(i = 1; i <= n; ++i)
            cout << (arr[i]+freq[i]) << ' ';
        cout << '\n';

        return;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    
    sol.solve();
    
    return 0;
}