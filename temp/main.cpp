/**
 * Codeforces Round #565 (Div. 3)
 * Problem C -  Lose it!
 * Time: 109 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution
{
public:
    int solve()
    {
        int ans = 15, n, num, cnt;

        cin >> n;
        
        for(int i = 0; i < 15; ++i)
        {
            num = n + i;
            cnt = 0;

            while(num % 2 == 0) { ++cnt; num /= 2; }

            ans = min(i + 15-cnt, ans);
        }

        return ans;
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