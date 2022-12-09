/**
 * Codeforces Round #625 (Div. 2, based on Technocup 2020 Final Round)
 * Problem B - Journey Planning
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>
 
using namespace std;

typedef long long int ll;
 
class Solution
{

public:
    ll solve()
    {
        int n, i, num;
        ll mx;
        map <int, ll> mp;
        map <int, ll>::iterator it;

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> num;
            mp[num-i] += num;
        }

        mx = 0;
        for(it = mp.begin(); it != mp.end(); ++it)
            if(it->second > mx)
                mx = it->second;
 
        return mx;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
 
    Solution sol;
 
    cout << sol.solve() << '\n';
 
    return 0;
}