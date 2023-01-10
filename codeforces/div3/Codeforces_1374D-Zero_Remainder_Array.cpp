/**
 * Codeforces Round #653 (Div. 3)
 * Problem D - Zero Remainder Array
 * Simpler than editorial
 * TIME: 140 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>
 
using namespace std;

typedef long long int ll;

class Solution
{
    int n, k, num, rem;
    map <int, int> mp;
    map <int, int>::iterator it;
    ll mx;
public:
    void solve()
    {
        cin >> n >> k;

        while(n--)
        {
            cin >> num;

            rem = num % k;

            if(rem) ++mp[k - rem];
        }

        mx = 0;
        for(it = mp.begin(); it != mp.end(); ++it)
            mx = max(mx, it->first + ll(it->second-1) * k);

        if(mx) cout << (mx+1) << '\n';
        else cout << "0\n";

        mp.clear();

        return;
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
        sol.solve();
 
    return 0;
}