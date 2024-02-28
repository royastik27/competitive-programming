/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

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
    vector <ll> p;
    vector <ll>::iterator LB;

    ll check(ll tot, ll u)
    {
            if(tot <= u) {
                    int cnt = u - tot;

                    ll right = ll(u+1)*u / 2;
                    ll left = ll(cnt+1)*cnt / 2;

                    return (right - left); 
                }
                else {
                    // tot > u
                    int cnt = (u+1) - tot;

                    ll right = ll(u+1)*u / 2;
                    ll left = ll(cnt+1)*cnt / 2;

                    return (right - left); 
                }
    }
public:
    void solve()
    {
        int n, i, ai, q, l;
        ll u;
        // ll tot;

        cin >> n;

        p.resize(n+1);

        p[0] = 0;
        for(i = 1; i <= n; ++i) {
            cin >> ai;
            p[i] = p[i-1] + ai;
        }

        cin >> q;

        while(q--) {
            cin >> l >> u;

            u = p[l-1] + u;

            LB = lower_bound(p.begin(), p.end(), u);

            if(LB != p.end() && (*LB == u || *LB == u+1)) {
                int r = distance(p.begin(), LB);

                cout << r << ' ';
            }
            else {
                int r = distance(p.begin(), LB);

                if(l == r) {
                    cout << r << ' ';
                }
                else {
                    // check r and r-1;
                    ll tot_r = p[r] - p[l-1];
                    ll tot_r1 = p[r-1] - p[l-1];

                    if(r > n)
                        cout << (r-1) << ' ';
                    else  {
                        ll inc_r = check(tot_r, u);
                        ll inc_r1 = check(tot_r1, u);

                        if(inc_r1 == inc_r)
                            cout << (r-1) << ' ';
                        else if(inc_r1 >= inc_r)
                            cout << (r-1) << ' ';
                        else
                            cout << (r) << ' ';
                    }
                    
                }

                // cout << "LB: " << r << '\n';

                // if(l != r)
                //     --r;

                // cout << "HERE\n";

                // cout << r << ' ';

                // if(l == r) {
                //     tot = p[r] - p[r-1];
                // }
                // else {
                //     --r;
                //     // tot = p[r] - p[l-1];
                // }
            }
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
    int TC;

    cin >> TC;

    while(TC--)
        sol.solve();

    return 0;
}