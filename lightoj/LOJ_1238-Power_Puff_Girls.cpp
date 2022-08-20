/**
 * LightOJ 1238 - Power Puff Girls
 * TIME: 4 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define LIM 20
#define INF 400

int r_move[4] = { 0, 0, -1, 1 }, c_move[4] = { -1, 1, 0, 0 };

class Solution {
    int row, col, x, y, dis[LIM][LIM];
    char grid[LIM][LIM];

    void go(int i, int j)
    {
        queue <pair <int, int> > que;
        pair <int, int> curr, node;
        int k;

        que.push(make_pair(i, j));

        while(!que.empty())
        {
            curr = que.front();
            que.pop();

            for(k = 0; k < 4; ++k)
            {
                node.first = curr.first + r_move[k];
                node.second = curr.second + c_move[k];

                if(node.first < 0 || node.first == row || node.second < 0 || node.second == col || grid[node.first][node.second] == '#' || dis[node.first][node.second] <= dis[curr.first][curr.second] + 1)
                    continue;

                dis[node.first][node.second] = dis[curr.first][curr.second] + 1;

                if(node.first == x && node.second == y) return;

                que.push(make_pair(node.first, node.second));
            }
        }

        return;
    }

    void readyDis()
    {
        int i, j;
        for(i = 0; i < row; ++i)
            for(j = 0; j < col; ++j)
                dis[i][j] = INF;

        return;
    }
public:
    int solve()
    {
        cin >> row >> col;

        int i, j;
        char ch;
        vector <pair <int, int> > girl;

        for(i = 0; i < row; ++i)
        {
            for(j = 0; j < col; ++j)
            {
                cin >> ch;
                if(ch == 'm') ch = '#';

                if(ch == 'h')
                    { x = i; y = j; }
                else if(ch >= 'a')
                    girl.push_back(make_pair(i, j));

                grid[i][j] = ch;
            }
        }

        int ans = 0;
        for(i = 0; i < 3; ++i)
        {
            readyDis();
            dis[girl[i].first][girl[i].second] = 0;

            go(girl[i].first, girl[i].second);
            ans = max(dis[x][y], ans);
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    int TC, k = 0;
    cin >> TC;

    while(TC--)
        cout << "Case " << ++k << ": " << sol.solve() << '\n';
    
    return 0;
}