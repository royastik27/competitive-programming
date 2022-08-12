/**
 * Codeforces Round #363 (Div. 2)
 * Problem C - Vacations
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 100
#define NONE 0
#define CONTEST 1
#define GYM 2

class Solution {
    int dp[3][LIM + 1];
public:
    int solve()
    {
        int n, arr[LIM], i;

        cin >> n;
        for(i = 0; i < n; ++i) cin >> arr[i];

        dp[NONE][n] = dp[CONTEST][n] = dp[GYM][n] = 0;

        for(i = n - 1; i >= 0; --i)
        {
            dp[NONE][i] = max(max(dp[CONTEST][i+1], dp[GYM][i+1]), dp[NONE][i+1]);

            switch(arr[i])
            {
                case 0:
                    dp[CONTEST][i] = 0;
                    dp[GYM][i] = 0;
                    break;
                case 1:
                    dp[CONTEST][i] = max(dp[GYM][i+1], dp[NONE][i+1]) + 1;
                    dp[GYM][i] = 0;
                    break;
                case 2:
                    dp[CONTEST][i] = 0;
                    dp[GYM][i] = max(dp[CONTEST][i+1], dp[NONE][i+1]) + 1;
                    break;
                default:
                    dp[CONTEST][i] = max(dp[GYM][i+1], dp[NONE][i+1]) + 1;
                    dp[GYM][i] = max(dp[CONTEST][i+1], dp[NONE][i+1]) + 1;
            }
        }

        return n - max(max(dp[CONTEST][0], dp[GYM][0]), dp[NONE][0]);
    }
};

class Solution2 {
    int dp[3][LIM + 1];
public:
    int solve()
    {
        int n, arr[LIM], i;
 
        cin >> n;
        for(i = 0; i < n; ++i) cin >> arr[i];
 
        dp[NONE][n] = dp[CONTEST][n] = dp[GYM][n] = 0;
 
        for(i = n - 1; i >= 0; --i)
        {
            dp[NONE][i] = max(dp[CONTEST][i+1], dp[GYM][i+1]);
 
            switch(arr[i])
            {
                case 0:
                    dp[CONTEST][i] = dp[CONTEST][i+1];
                    dp[GYM][i] = dp[GYM][i+1];
                    break;
                case 1:
                    dp[CONTEST][i] = max(dp[GYM][i+1], dp[NONE][i+1]) + 1;
                    dp[GYM][i] = dp[GYM][i+1];
                    break;
                case 2:
                    dp[CONTEST][i] = dp[CONTEST][i+1];
                    dp[GYM][i] = max(dp[CONTEST][i+1], dp[NONE][i+1]) + 1;
                    break;
                default:
                    dp[CONTEST][i] = max(dp[GYM][i+1], dp[NONE][i+1]) + 1;
                    dp[GYM][i] = max(dp[CONTEST][i+1], dp[NONE][i+1]) + 1;
            }
        }
 
        return n - max(max(dp[CONTEST][0], dp[GYM][0]), dp[NONE][0]);
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