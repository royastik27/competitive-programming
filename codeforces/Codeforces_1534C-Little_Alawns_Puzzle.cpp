/**
 * Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
 * Problem C - Little Alawn's Puzzle
 * Simpler than the editorial
 * TIME: 202 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define MOD 1000000007
#define LIM 400000

class Solution {
    int first[LIM], second[LIM], pos[LIM+1];
    bool vis[LIM];

    int power(int base, int p)
    {
        if(!p) return 1;

        if(p & 1)
            return (ll)base * power(base, p-1) % MOD;
        else return power((ll)base*base%MOD, p/2);
    }
public:
    int solve()
    {
        int n, i, curr, cnt;

        cin >> n;
        for(i = 0; i < n; ++i)
        {
            cin >> first[i];
            vis[i] = false;
        }
        for(i = 0; i < n; ++i)
        {
            cin >> second[i];
            pos[second[i]] = i;
        }

        cnt = 0;
        for(i = 0; i < n; ++i)
        {
            if(vis[i]) continue;

            curr = i;
            vis[curr] = true;

            while((curr = pos[first[curr]]) != i)
                vis[curr] = true;

            ++cnt;
        }

        return power(2, cnt);
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
