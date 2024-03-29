/**
* Educational Codeforces Round 103 (Rated for Div. 2)
* Problem C - Longest Simple Cycle
* TIME: 93 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <cmath>

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
    int n;
    vector <int> a, b, c;

    int abs(int n) { return (n < 0 ? 0-n : n); }
public:
    void solve()
    {
        int i;

        cin >> n;

        a.resize(n);
        b.resize(n);
        c.resize(n);

        for(i = 0; i < n; ++i) {
            cin >> c[i];
        }
        for(i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // processing
        ll ans = 0, rightMx = 0, left, inner = 2;

        for(i = n-1; i > 0; --i) {

            left = abs(a[i]-b[i]) + 1;

            rightMx = max(ll(c[i]), rightMx+c[i]-inner+2);

            ans = max(ans, left+rightMx);

            if(left == 1) {
                inner = 2;
                rightMx = 0;
            }
            else
                inner = left;
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