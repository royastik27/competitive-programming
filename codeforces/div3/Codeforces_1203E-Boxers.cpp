/**
* Codeforces Round 579 (Div. 3)
* Problem E - Boxers
* TIME: 62 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int ll;

#define LIM 150000

class Solution
{
    int a[LIM];
    bool mp[LIM+2];
public:
    void solve()
    {
        int n, i, curr, ans;

        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> a[i];

        sort(a, a+n);

        memset(mp, 0, sizeof(mp));
        mp[0] = true;

        ans = 0;
        for(i = 0; i < n; ++i) {
            curr = a[i];

            if(mp[curr+1]) continue;

            if(!mp[curr-1])
                mp[curr-1] = true;
            else if(!mp[curr])
                mp[curr] = true;
            else
                mp[curr+1] = true;

            ++ans;
        }

        cout << ans << '\n';        

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