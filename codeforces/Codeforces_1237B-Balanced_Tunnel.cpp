/**
 * Codeforces Global Round 5
 * Problem B - Balanced Tunnel
 * Time: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define LIM 100001

class Solution
{
    bool mp[LIM];
public:
    int solve()
    {
        int n, i, ans = 0, el;
        queue <int> que;

        cin >> n;        

        // INPUT
        for(i = 0; i < n; ++i)
        {
            cin >> el;
            que.push(el);
        }
        memset(mp, 0, (n+1)*sizeof(bool));

        // PROCESSING
        while(n--)
        {
            cin >> el;

            while(mp[que.front()])
                que.pop();

            if(el == que.front())
                que.pop();
            else
                { ++ans; mp[el] = true; }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    cout << sol.solve() << '\n';
    
    return 0;
}