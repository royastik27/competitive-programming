/**
 * Codeforces Global Round 14
 * Problem C - Phoenix and Towers
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    int n, m, num, idx;
    vector < pair <int, int> > vec;
public:
    void solve()
    {
        cin >> n >> m >> idx;

        int i;
        for(i = 0; i < n; ++i)
        {
            cin >> num;
            vec.push_back({ num, i });
        }
        
        sort(vec.begin(), vec.end());
        vector <int> ans(n);

        for(i = 0, idx = 1; i < n; ++i)
        {
            ans[vec[i].second] = idx;

            if(++idx > m) idx = 1;
        }

        cout << "YES\n";
        for(i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';

        vec.clear();

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