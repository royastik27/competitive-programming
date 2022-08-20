/**
 * CSES 1193 - Labyrinth
 * TIME: 0.07 s
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

#define LIM 1000
#define INF 1000000

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int r_move[4] = { 0, 0, -1, 1 }, c_move[4] = { -1, 1, 0, 0 };

class Solution {
    char grid[LIM][LIM];
    int dis[LIM][LIM], move[LIM][LIM], n, m, x1, y1, x, y;
    stack <int> path;

    void getPath(int i, int j)
    {
        if(i == x && j == y) return;

        path.push(move[i][j]);

        switch(move[i][j])
        {
            case LEFT:
                getPath(i, j+1);
                break;
            case RIGHT:
                getPath(i, j-1);
                break;
            case UP:
                getPath(i+1, j);
                break;
            default: // down
                getPath(i-1, j);
        }

        return;
    }

    void go()
    {
        queue <pair <int, int> > que;
        pair <int, int> curr, node;
        int i;

        que.push(make_pair(x, y));

        while(!que.empty())
        {
            curr = que.front();
            que.pop();

            for(i = 0; i < 4; ++i)
            {
                node.first = curr.first + r_move[i];
                node.second = curr.second + c_move[i];

                if(node.first < 0 || node.first == n || node.second < 0 || node.second == m || grid[node.first][node.second] == '#' || dis[node.first][node.second] <= dis[curr.first][curr.second] + 1 )
                    continue;

                dis[node.first][node.second] = dis[curr.first][curr.second] + 1;
                move[node.first][node.second] = i;

                if(node.first == x1 && node.second == y1) return;

                que.push(make_pair(node.first, node.second));
            }
        }

        return;
    }

    void printPath()
    {
        cout << "Path:\n";

        int i, j;
        char ch;
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < m; ++j)
            {
                switch(move[i][j])
                {
                    case LEFT:
                        ch = 'L';
                        break;
                    case RIGHT:
                        ch = 'R';
                        break;
                    case UP:
                        ch = 'U';
                        break;
                    case DOWN:
                        ch = 'D';
                        break;
                    default:
                        ch = '#';
                }

                if(i == x && j == y) ch = 'A';

                cout << ch;
            }
            cout << '\n';
        }

        return;
    }
public:
    void solve()
    {
        int i, j;
        char ch;

        cin >> n >> m;
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < m; ++j)
            {
                cin >> ch;
                grid[i][j] = ch;

                if(ch == 'A')
                {
                    x = i;
                    y = j;
                    dis[i][j] = 0;
                }
                else
                {
                    if(ch == 'B') { x1 = i; y1 = j; }
                    dis[i][j] = INF;
                    // move[i][j] = 4;
                }
            }
        }

        go();

        if(dis[x1][y1] == INF)
            cout << "NO\n";
        else
        {
            cout << "YES\n" << dis[x1][y1] << '\n';

            // printPath();
            getPath(x1, y1);

            char arr[4] = { 'L', 'R', 'U', 'D' };

            while(!path.empty())
            {
                cout << arr[path.top()];
                path.pop();
            }
            cout << '\n';
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    sol.solve();

    char ch;
    cin >> ch;

    return 0;
}
