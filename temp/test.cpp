/**
 * Educational Codeforces Round 79 (Rated for Div. 2)
 * Problem C - Stack of Presents
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 100000

typedef long long int ll;

class Solution
{
    int n, m, a[LIM], b_i, i, j;
    ll ans;
    bool vis[LIM + 1];
public:
    ll solve()
    {
        cin >> n >> m;

        for(i = 0; i < n; ++i) cin >> a[i];

        memset(vis, 0, n+1);
        ans = 0;

        for(i = 0, j = 0; j < m; ++j)
        {
            cin >> b_i;

            if(!vis[b_i])
            {
                while(a[i] != b_i)
                {
                    vis[a[i]] = true;
                    ++i;
                }

                ans += 2 * (i - j);
                ++i;
            }

            ++ans;
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        cout << sol.solve() << '\n';

    return 0;
}

/**
 * Educational Codeforces Round 79 (Rated for Div. 2)
 * Problem C - Stack of Presents
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 100000
#define MOD 1000000007

class Solution
{
    int a[LIM], b[LIM], n, x, ans, i;
    bool vis[LIM+1];
public:
    int solve()
    {
        cin >> n;
        
        memset(vis, 0, n+1);

        for(i = 0; i < n; ++i)
            cin >> a[i];
        
        for(i = 0; i < n; ++i)
            cin >> b[i];

        ans = 1;
        for(i = 0; i < n; ++i)
        {
            cin >> x;
            
            if(!x & !vis[a[i]] & !vis[b[i]] & (a[i] != b[i]))
                ans = ans * 2 % MOD;

            vis[a[i]] = vis[b[i]] = true;
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        cout << sol.solve() << '\n';

    return 0;
}