/**
 * Codeforces Round #368 (Div. 2)
 * Problem B - Bakery
 * TIME: 77 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

#define LIM 100000

class Solution {

public:
    int solve()
    {
        int n, m, i, j, k, mn = INT_MAX, weight;
        vector <int> edge[3];
        bool storage[LIM + 1];

        cin >> n >> m >> k;
        memset(storage, 0, n+1);

        while(m--)
        {
            cin >> i >> j >> weight;

            edge[0].push_back(i);
            edge[1].push_back(j);
            edge[2].push_back(weight);
        }
        m = edge[0].size();

        for(i = 0; i < k; ++i)
        {
            cin >> j;
            storage[j] = true;
        }

        for(i = 0; i < m; ++i)
        {
            if(storage[edge[0][i]] != storage[edge[1][i]] && edge[2][i] < mn)
                mn = edge[2][i];
        }

        return (mn == INT_MAX) ? -1 : mn;
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