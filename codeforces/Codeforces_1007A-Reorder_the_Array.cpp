/**
 * Codeforces Round #497 (Div. 1)
 * Problem A - Reorder the Array
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>

using namespace std;

#define LIM 100000

class Solution {

public:
    int solve()
    {
        int n, i, arr[LIM], ans = 0;
        map <int, int> mp;
        map <int, int>::iterator it;

        cin >> n;
        for(i = 0; i < n; ++i)
        {
            cin >> arr[i];
            ++mp[arr[i]];
        }

        for(i = 0; i < n; ++i)
        {
            it = mp.upper_bound(arr[i]);

            if(it == mp.end()) continue;

            ++ans;
            if(--it->second == 0) mp.erase(it);
        }

        return ans;
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
