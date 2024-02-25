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

class Solution
{
    bool check(int i, int j, char ch)
    {
        if(i < 0 || i == n || j < 0 || j == m)
            return false;

        return (a[i][j] == ch);
    }
    void first()
    {
        int i, j;

        for(i = 0; i < n; ++i) {
            for(j = 0; j < m; ++j) {

                if(a[i][j] == inp[1]) {

                    for(k = 0; k < 4; ++k) {
                        x = i + row_move[k];
                        y = j + col_move[k];

                        if(check(x, y, inp[2]))
                            ++mem[i][j];
                    }
                }
            }
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