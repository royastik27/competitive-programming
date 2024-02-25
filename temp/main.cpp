/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional>

using namespace std;
// using namespace __gnu_pbds;

typedef long long int ll;
typedef pair <int, int> pii;

// typedef tree<int , null_mapped_type ,  less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;
// typedef tree<int , null_mapped_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

#define LIM 1000

int row_move[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int col_move[8] = { -1, 0, 1, -1, 1, -1, 0, 1 }

class Solution
{
    int n, m, a[LIM][LIM], mem[LIM][LIM];
    ll ans;

    bool check(int i, int j, char ch)
    {
        if(i < 0 || i == n || j < 0 || j == m)
            return false;

        return (a[i][j] == ch);
    }

    int check2(int i, int j)
    {
        if(i < 0 || i == n || j < 0 || j == m)
            return 0;

        return mem[i][j];
    }

    void first()
    {
        int i, j, x, y, k;

        for(i = 0; i < n; ++i) {
            for(j = 0; j < m; ++j) {

                if(a[i][j] == inp[1]) {

                    for(k = 0; k < 8; ++k) {
                        x = i + row_move[k];
                        y = j + col_move[k];

                        if(check(x, y, inp[2]))
                            ++mem[i][j];
                    }
                }
            }
        }

        return;
    }

    void second()
    {
        int i, j, res, x, y, k;

        for(i = 0; i < n; ++i) {
            for(j = 0; j < m; ++j) {

                if(a[i][j] == inp[0]) {
                    res = 0;

                    for(k = 0; k < 8; ++k) {
                        x = i + row_move[k];
                        y = j + col_move[k];

                        res += check2(x, y);
                    }
                }
            }

            ans = max(ans, res);
        }
    }

public:
    void solve()
    {
        int n, m;

        cin >> n >> m;

        memset(mem, 0, sizeof(mem));

        for(i = 0; i < n; ++i) {
            for(j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        cin >> inp;

        first();

        ans = 0;
        second();

        cout << ans << '\n';

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}