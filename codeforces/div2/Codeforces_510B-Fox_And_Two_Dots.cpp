/**
* Codeforces Round 290 (Div. 2)
* Problem B - Fox And Two Dots
* TIME: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

typedef long long int ll;

#define LIM 50

class Solution
{
    int n, m, rowmove[4], colmove[4], beg, end;
    char a[LIM][LIM];
    bool vis[LIM][LIM];

    bool flood(int x, int y, int step = 0)
    {
        int i, j, newX, newY;

        vis[x][y] = true;

        ++step;
        for(i = 0; i < 4; ++i) {
            newX = x + rowmove[i];
            newY = y + colmove[i];

            if(newX < 0 || newX == n || newY < 0 || newY == m || a[newX][newY] != a[x][y])
                continue;

            if(!vis[newX][newY]) {
                if(flood(newX, newY, step))
                    return true;
            }
            else if(newX == beg && newY == end && step >= 4)
                return true;
        }

        return false;
    }
public:
    Solution()
    {
        // up
        rowmove[0] = -1;
        colmove[0] = 0;

        // left
        rowmove[1] = 0;
        colmove[1] = -1;

        // right
        rowmove[2] = 0;
        colmove[2] = 1;

        // down
        rowmove[3] = 1;
        colmove[3] = 0;
    }
    void solve()
    {
        int i, j;

        cin >> n >> m;

        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
                cin >> a[i][j];
        
        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j) {

                memset(vis, 0, sizeof(vis));

                beg = i;
                end = j;

                if(flood(i, j)) {
                    cout << "Yes\n";
                    return;
                }
            }

        cout << "No\n";

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}