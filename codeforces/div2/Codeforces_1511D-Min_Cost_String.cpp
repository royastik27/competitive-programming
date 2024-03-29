/**
* Educational Codeforces Round 107 (Rated for Div. 2)
* Problem D - Min Cost String
* TIME: 46 ms
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
    int n, k;
public:
    void solve()
    {
        int i, j;
        string ans;

        cin >> n >> k;

        for(i = 0; i < k; ++i) {
            ans.push_back('a'+i);

            for(j = i+1; j < k; ++j) {
                ans.push_back('a'+i);
                ans.push_back('a'+j);
            }
        }

        int sz = ans.size();

        for(i = 0; i < n; ++i) {
            cout << ans[i%sz];
        }
        cout << '\n';

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    // int TC;

    // cin >> TC;

    // while(TC--)
        sol.solve();

    return 0;
}