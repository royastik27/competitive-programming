/**
* 11th CPU CSE Programming Contest
* Problem G - Maximize the Tastiness
* TIME: 3s
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <bitset>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional>

using namespace std;
// using namespace __gnu_pbds;

typedef long long int ll;
typedef pair <int, int> pii;

// typedef tree<int , null_mapped_type ,  less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;
// typedef tree<int , null_mapped_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

#define LIM 110

class Solution
{
    int a[LIM][LIM], n, m, ans;
    bitset <15> col;

    void run(int row = 0, int sum = 0)
    {
        if(row == n) {
            ans = max(ans, sum);
            return;
        }

        int i;

        run(row+1, sum);

        for(i = 0; i < m; ++i) {
            if(!col[i]) {

                col[i] = true;
                run(row+1, sum + a[row][i]);
                col[i] = false;
            }
        }

        return;
    }
public:
    void solve()
    {
        int i, j;

        cin >> n >> m;
        
        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j) {
                cin >> a[i][j];
            }

        ans = 0;
        run();

        cout << ans << '\n';

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