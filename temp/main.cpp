/**
 * Educational Codeforces Round 136 (Rated for Div. 2)
 * Problem B - Array Recovery
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

#define LIM 2000

class Solution {
    int arr[LIM];
    map <vector <pair <int, int> > > mp;
public:
    void solve()
    {
        int n, i, j, sum;

        cin >> n;
        for(i = 0; i < n; ++i) cin >> arr[i];

        for(i = 0; i < n; ++i)
        {
            sum = 0;
            for(j = i; j < n; ++j)
            {
                sum += arr[j];
                mp[sum].push_back({i+1, j+1});
            }
        }

        mp.clear();
        
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        sol.solve();
    
    return 0;
}