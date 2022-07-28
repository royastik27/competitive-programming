/**
 * UVA 574 - Sum It Up
 * RANK: 2674 out of 9371
 * TIME: 0.000 sec
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

#define LIM 101
#define WHITE 0
#define BLACK 1

class Solution {
    int n;
    vector <int> adj[LIM];
    bitset <LIM> visited, tempVisited, color;

    int go(int node, int parentColor)
    {
        // FOR CYCLES
        if(tempVisited[node])
        {
            if(color[node] == parentColor && parentColor == BLACK)
                return -LIM;
            else return 0;
        }

        tempVisited[node] = true;

        cout << "Called " << node << " with " << parentColor << '\n';

        // RECURSIVE CALLS
        int white = 0, black = (parentColor == WHITE) ? 1 : 0;

        int sz = adj[node].size(), curr;

        for(int i = 0; i < sz; ++i)
        {
            curr = adj[node][i];

            white += go(curr, WHITE);

            if(parentColor == WHITE) black += go(curr, BLACK);
        }

        if(black > white)
        {
            color[node] = BLACK;
            cout << "Color of " << node << " is black\n";
            return black;
        }
        else { color[node] = WHITE; cout << "Color of " << node << " is white\n"; return white; }
    }
public:
    void solve()
    {
        int nEdges, i, j;

        // INPUT
        cin >> n >>  nEdges;

        while(nEdges--)
        {
            cin >> i >> j;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        // CALLING FUNCTION
        for(i = 1; i <= n; ++i)
            if(!visited[i]) { tempVisited = visited; go(i, WHITE); visited = tempVisited; }

        // PRINTING RESULT
        cout << color.count() << '\n';
        for(i = 1; i <= n; ++i)
        {
            if(color[i]) cout << i << ' ';
        }
        cout << '\n';

        // RESETTING
        for(i = 1; i <= n; ++i) adj[i].clear();
        visited.reset();
        color.reset();

        return;
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
        sol.solve();
    
    return 0;
}