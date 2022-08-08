/**
 * AtCoder Beginner Contest 258
 * Problem B - Number Box
 * TIME: 5 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 11

class Solution {
    char grid[LIM][LIM];
    int n;
    int rmove[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    int cmove[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

    long long int make_move(int i, int j, int move, int state = 0, long long int sum = 0)
    {
        if(state == n) return sum;

        if(i < 0) i = n - 1;
        else if(i == n) i = 0;
        
        if(j < 0) j = n - 1;
        else if(j == n) j = 0;

        return make_move(i + rmove[move], j + cmove[move], move, state + 1, sum * 10 + (int)grid[i][j] - '0');
    }

    long long int go(int i, int j)
    {
        long long int ans = 0;

        for(int move = 0; move < 8; ++move)
            ans = max(make_move(i, j, move), ans);
        
        return ans;
    }
public:
    void solve()
    {
        cin >> n;

       int i, j;
       for(i = 0; i < n; ++i)
        cin >> grid[i];

        long long int ans = 0;
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                ans = max(go(i, j), ans);

        cout << ans << '\n';

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    sol.solve();
    
    return 0;
}