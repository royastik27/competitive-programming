/**
 * Codeforces Round #826 (Div. 3)
 * Problem C - Minimize the Thickness
 * TIME: 1575 ms
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
    map <int, vector <pair <int, int> > > mp;
    map <int, vector <pair <int, int> > >::iterator it;
public:
    int solve()
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

        int mn = n, bound, mx, diff, sz;

        for(it = mp.begin(); it != mp.end(); ++it)
        {
            sz = it->second.size();

            bound = 0;
            mx = 0;

            for(i = 0; i < sz; ++i)
            {
                if(it->second[i].first == bound + 1)
                {
                    bound = it->second[i].second;

                    diff = it->second[i].second - it->second[i].first + 1;
                    
                    if(diff > mx) mx = diff;
                }
            }

            if(bound == n)
                if(mx < mn) mn = mx;
        }

        mp.clear();
        
        return mn;
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