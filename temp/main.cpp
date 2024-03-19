/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <climits>
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
    string str;
    vector <bool> forw, back;
public:
    void solve()
    {
        cin >> n >> str;

        str = "#" + str;

        forw.resize(n+3);
        back.resize(n+3);

        int zero, one;
        zero = one = 0;
        forw[0] = true;

        for(i = 1; i <= n; ++i) {
            if(str[i] == '1')
                ++one;
            else
                ++zero;

            if(zero >= one)
                forw[i] = true;
            else
                forw[i] = false;
        }
        
        back[n+1] = true;
        zero = one = 0;
        for(i = n; i >= 0; --i) {
            if(str[i] == '1')
                ++one;
            else
                ++zero;

            if(one >= zero)
                back[i] = true;
            else
                back[i] = false;
        }

        int middle = (n+1) / 2;
        int mn_dis = INT_MAX;
        int ans = 0;

        for(i = 0; i <= n; ++i) {
            if(forw[i] && back[i+1]) {
                // true
                dis = abs(middle - i);

                if(dis < mn_dis) {
                    mn_dis = dis;
                    ans = i;
                }
            }
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