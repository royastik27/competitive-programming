/**
 * Technocup 2021 - Elimination Round 2
 * Problem C - Bouncing Ball
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <climits>

using namespace std;

#define LIM 100000

class Solution
{
    int n, p, k, x, y, i, mem[LIM], idx, mn;
    string s;

    inline int fill_cost(int idx)
    {
        return !bool(s[idx]-'0') * x;
    }
public:
    int solve()
    {
        cin >> n >> p >> k >> s >> x >> y;

        // memorization
        for(i = n-1; i >= n - k; --i)
            mem[i] = fill_cost(i);

        for(; i >= 0; --i)
            mem[i] = fill_cost(i) + mem[i+k];

        // DP
        mn = INT_MAX;
        for(i = n - p; i >= 0; --i)
            mn = min(mn, i * y + fill_cost(i + p - 1) + ((idx = i + p + k) > n ? 0 : mem[idx-1]));
        
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