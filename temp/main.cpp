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

public:
    void solve()
    {
        cin >> n; 

        for(i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for(i = 0; i < n; ++i) {
            cin >> b[i];
        }

        forw.resize(n, -1);

        i = 0;
        j = 0;
        while(i < n && j < n) {
            if(a[i] == b[j]) {
                forw[j] = i;
                ++j;
            }

            ++i;
        }

        // for back
        back.resize(n, -1);

        i = n-1;
        j = n-1;
        while(i >= 0 && j >= 0) {
            if(a[i] == b[j]) {
                back[j] = i;
                --j;
            }

            --i;
        }

        // processing
        ans = n;

        for(i = 0; i < n; ++i) {
            for(j = i; j < n; ++j) {
                // i to j inclusive
                if(forw[i] != -1 && back[j] != -1 && forw[i] < back[j]) {
                    ans = min(ans, back[j]-forw[i]-1);
                }
            }
        }

        cout << ans << '\n';

        forw.clear();
        back.clear();

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