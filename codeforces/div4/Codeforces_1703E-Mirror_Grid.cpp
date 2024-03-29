/**
* Codeforces Round 806 (Div. 4)
* Problem E - Mirror Grid
* TIME: 31 ms
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

#define LIM 110

class Solution
{
    int n;
    char a[LIM][LIM];

    int process(int x, int y)
    {
        int zero, one;

        zero = one = 0;

        for(int i = 0; i < 4; ++i) {
            if(a[x][y] == '1') ++one;
            else ++zero;

            int temp = y;
            y = n - x + 1;
            x = temp;
        }

        return min(zero, one);
    }
public:
    void solve()
    {
        int i, j;

        cin >> n;

        for(i = 1; i <= n; ++i) {
            for(j = 1; j <= n; ++j) {
                cin >> a[i][j];
            }
        }

        int halfN = n / 2, ans = 0;

        for(i = 1; i <= halfN; ++i) {
            ans += process(i, i);

            for(j = i+1; j <= n-i; ++j)
                ans += process(i, j);
        }

        cout << ans << '\n';

        return;
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
        sol.solve();

    return 0;
}