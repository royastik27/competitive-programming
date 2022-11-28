/**
 * Codeforces Round #753 (Div. 3)
 * Problem D - Blue-Red Permutation
 * O(n) approach (without sorting)
 * TIME: 77 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 200000

class Solution
{
    int blue[LIM+1], red[LIM+1], preRed[LIM+1], arr[LIM];
    bool vis[LIM+1];
public:
    bool solve()
    {
        int n, i, used, cnt, curr;
        char color;

        cin >> n;

        memset(blue, 0, (n+1)*sizeof(int));
        memset(red, 0, (n+1)*sizeof(int));
        memset(vis, 0, n+1);

        // input

        for(i = 0; i < n; ++i)
            cin >> arr[i];

        for(i = 0; i < n; ++i)
        {
            cin >> color;
            curr = arr[i];

            if(color == 'B')
            {
                if(curr > n) ++blue[n];
                else if(curr > 0) ++blue[curr];
            }
            else
            {
                if(curr < 1) ++red[1];
                else if(curr <= n) ++red[curr];
            }
        }

        // processing
        preRed[1] = red[1];
        for(i = 2; i <= n; ++i)
            preRed[i] = red[i] + preRed[i-1];

        // filling up red
        used = 0;
        for(i = n; i >= 1; --i)
        {
            if(preRed[i] == used)
                break;
            
            ++used;
            vis[i] = true;

            if(red[i] >= used) used = 0;
            else used -= red[i];
        }

        // for blue
        cnt = 0;
        for(i = n; i >= 1; --i)
        {
            if(blue[i]) cnt += blue[i];

            if(!vis[i])
            {
                if(cnt) --cnt;
                else return false;
            }
        }

        return true;
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
        if(sol.solve()) cout << "YES\n";
        else cout << "NO\n";

    return 0;
}