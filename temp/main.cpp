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
    int n;
    vector <ll> a, b;
public:
    void solve()
    {
        int i;
        
        cin >> n;

        a.resize(n+1);
        b.resize(n+1);

        for(i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        for(i = 1; i <= n; ++i) {
            cin >> b[i];
        }

        // processing
        ll diff, denom, m;

        for(i = 1; i <= n - 3; ++i) {
            if(a[i] == b[i])
                continue;

            diff = b[i] - a[i];
            denom = a[i+1] + a[i+2];

            if(diff % denom != 0) {
                break;
            }

            m = diff / denom;

            if(m < 1)
                break;

            a[i] = b[i]; // no need
            if(m & 1) {
                int temp = a[i+1];
                a[i+1] = 0 - a[i+2];
                a[i+2] = 0 - temp;

                a[i+3] = a[i+3] + a[i+1] + a[i+2];
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
        }

        for(i = 1; i <= n; ++i) {
            if(a[i] != b[i]) {
                break;
            }
        }

        if(i > n)
            cout << "YES\n";
        else cout << "NO\n";

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