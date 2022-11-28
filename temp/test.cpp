/**
 * Codeforces Round #316 (Div. 2)
 * Problem B - Simple Game
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 200000

class Solution
{
    int blue[LIM+1], red[LIM+1], arr[LIM];
    bool vis[LIM+1];
public:
    bool solve()
    {
        int n, i, used;
        char color;
        memset(blue, 0, (n+1)*sizeof(int));
        memset(red, 0, (n+1)*sizeof(int));
        memset(vis, 0, n+1);

        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> arr[i];

        for(i = 0; i < n; ++i)
        {
            cin >> color;
            if(color == 'B') ++blue[arr[i]];
            else ++red[arr[i]];
        }

        for(i = n-1; i >= 1; --i)
            blue[i] += blue[i+1];

        // for(i = 2; i <= n; ++i)
        //     red[i] += red[i-1];

        // filling up
        red[0] = 0;
        for(i = 1; i <= n; ++i)
        {
            if(red[i])
        }

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
        cout << sol.solve() << '\n';

    return 0;
}