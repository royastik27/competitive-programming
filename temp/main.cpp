/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional>

using namespace std;
// using namespace __gnu_pbds;

typedef long long int ll;
typedef pair <int, int> pii;

// typedef tree<int , null_mapped_type ,  less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;
// typedef tree<int , null_mapped_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

int row_move[4] = { -1, 1, 0, 0};
int col_move[4] = { 0, 0, 1, -1 };

#define LIM 220

class Solution
{   
    int n;
    bool vis[LIM][LIM];
    char a[LIM][LIM];

    void perm(int row, int col)
    {
        if(row < 0 || row > 1 || col < 0 || col > n-1)
            return;

        if(can[row][col] == '>') {
            if(vis[row][col+1])
                return;
            
            process(row, col+1);
        }
        else {
            if(vis[row][col-1])
                return;
            
            process(row, col-1);
        }
        
        return;
    }
    void process(int row, int col)
    {
        int i, x, y;
        vis[row][col] = true;

        for(i = 0; i < 4; ++i) {
            x = row + row_move[i];
            y = col + col_move[i];

            perm(x, y);
        }        
    }
public:
    void solve()
    {
        int i;
        
        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> a[0][i];
        for(i = 0; i < n; ++i)
            cin >> a[1][i];

        memset(vis, 0, sizeof(vis));        

        process(0, 0);

        cout << (vis[1][n-1] ? "YES\n" : "NO\n");

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