/**
 * Educational Codeforces Round 95 (Rated for Div. 2)
 * Problem C - Mortal Kombat Tower
 * TIME: 77 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 200001

#define FRND 0
#define ME 1

class Solution
{
    int n, i, mem[2][LIM];
    bool a[LIM];
public:
    int solve()
    {
        cin >> n;

        for(i = 1; i <= n; ++i)
            cin >> a[i];

        mem[FRND][0] = mem[FRND][1] = mem[ME][1] = a[1];
        mem[ME][0] = 0;

        for(i = 2; i <= n; ++i)
        {
            // FRND at i
            mem[FRND][i] = a[i] + min(mem[ME][i-1], a[i-1] + mem[ME][i-2]);

            // ME at i
            mem[ME][i] = min(mem[FRND][i-1], mem[FRND][i-2]);
        }

        return min(mem[FRND][n], mem[ME][n]);
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