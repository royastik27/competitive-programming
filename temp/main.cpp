/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

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
    int a, b;
    bool front;
    vector <int> ans;

    void process(int idx)
    {
        if(front)
            ans[idx] = a++;
        else
            ans[idx] = b--;

        front ^= 1;
    }
public:
    void solve()
    {
        int n, k, i;

        cin >> n >> k;

        ans.resize(n+1);

        // for(i = 1; i <= n; ++i) {
        //     ans[i] = 0;
        // }

        a = 1;
        b = n;
        front = true;

        for(i = 1; i <= k; i += 2) {

            for(j = i; j <= n; j += k) {
                process(j);

                if(j + 1 <= n)
                    process(j+1);
            }
        }

        for(i = 1; i <= n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';

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