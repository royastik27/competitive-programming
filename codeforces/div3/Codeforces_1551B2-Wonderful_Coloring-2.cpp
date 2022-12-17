/**
 * Codeforces Round #734 (Div. 3)
 * Problem B2 - Wonderful Coloring - 2
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define LIM 200000

class Solution
{
    vector <int> pos[LIM+1];
    queue <int> less;
    int ans[LIM], n, num, k, i, j;
public:
    void solve()
    {
        cin >> n >> k;

        for(i = 0; i < n; ++i)
        {
            cin >> num;
            pos[num].push_back(i);
        }

        // generating answer
        memset(ans, 0, n*sizeof(int));

        for(i = 1; i <= n; ++i)
        {
            num = pos[i].size();
            
            if(num >= k)
            {
                for(j = 0; j < k; ++j)
                    ans[pos[i][j]] = j+1;

                pos[i].clear();
            }
            else
            {
                for(j = 0; j < num; ++j)
                    less.push(pos[i][j]);
            }
        }

        while(less.size() >= k)
        {
            for(j = 1; j <= k; ++j)
            {
                ans[less.front()] = j;
                less.pop();
            }
        }

        // printing answer
        for(i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';

        // clearing containers
        for(i = 1; i <= n; ++i)
            pos[i].clear();

        while(less.size())
            less.pop();

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