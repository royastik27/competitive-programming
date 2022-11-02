/**
 * Codeforces Round #790 (Div. 4)
 * Problem G - White-Black Balanced Subtrees
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

#define LIM 4000
#define WHITE 0
#define BLACK 1

class Solution {
    int color[LIM], ans;
    vector <int> adj[LIM];

    int * go(int node)
    {
        int i, sz = adj[node].size();
        int * arr = new int[2];

        arr[0] = arr[1] = 0;

        for(i = 0; i < sz; ++i)
        {
            int * temp = go(adj[node][i]);

            arr[WHITE] += temp[WHITE];
            arr[BLACK] += temp[BLACK];

            delete temp;
        }

        if(color[node] == WHITE) ++arr[WHITE];
        else ++arr[BLACK];

        if(arr[WHITE] == arr[BLACK]) ++ans;

        return arr;
    }
public:
    int solve()
    {
        int n, i, par;
        char ch;
        
        cin >> n;
        for(i = 1; i < n; ++i)
        {
            cin >> par;
            --par;
            adj[par].push_back(i);
        }
        for(i = 0; i < n; ++i)
        {
            cin >> ch;
            color[i] = (ch == 'W') ? WHITE : BLACK;
        }

        ans = 0;
        go(0);

        for(i = 0; i < n; ++i)  adj[i].clear();

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
