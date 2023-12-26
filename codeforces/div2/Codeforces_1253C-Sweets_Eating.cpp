/**
* Codeforces Round 600 (Div. 2)
* Problem C - Sweets Eating
* TIME: 155 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    void solve()
    {
        int n, m, i, lim;
        vector <int> a;
        vector <ll> seq_sum;
        ll ans;

        cin >> n >> m;
        a.resize(n);

        for(i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end());

        // sequential sum
        for(i = 0; i < m; ++i)
            seq_sum.push_back(a[i]);

        lim = n - m;
        for(; i < lim; ++i)
            seq_sum.push_back(a[i] + seq_sum[i-m]);

        // generating answer
        ans = 0;
        for(i = 0; i < m; ++i) {
            ans += a[i];
            cout << ans << ' ';
        }

        for(; i < n; ++i) {
            ans += a[i] + seq_sum[i-m];
            cout << ans << ' ';
        }

        cout << '\n';

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}