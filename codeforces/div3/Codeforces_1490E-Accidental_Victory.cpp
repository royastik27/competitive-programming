/**
 * Codeforces Round #702 (Div. 3)
 * Problem E - Accidental Victory
 * TIME: 78 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
 
class Solution
{
    int n, num, i;
    vector < pair <int, int> > vec;
    vector <int> ans;
    ll presum;
public:
    void solve()
    {
        cin >> n;

        for(i = 1; i <= n; ++i)
        {
            cin >> num;
            vec.push_back({ num, i });
        }

        // generating ans
        sort(vec.begin(), vec.end());

        presum = 0;
        for(i = 0; i < n; ++i)
        {
            if(vec[i].first > presum)
                ans.clear();

            ans.push_back(vec[i].second);

            presum += vec[i].first;
        }

        sort(ans.begin(), ans.end());

        // printing ans
        n = ans.size();
        cout << n << '\n';
        for(i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';
        
        // clearing container
        vec.clear();
        ans.clear();

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