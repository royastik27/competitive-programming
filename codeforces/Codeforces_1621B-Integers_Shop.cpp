/**
* Hello 2022
* Problem B - Integers Shop
* TIME: 233 ms
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
    int n;
public:
    void solve()
    {
        int i, left, right, coins, b, e, one_b, one_e, one_ans, left_ans, right_ans;

        cin >> n;

        // for first one
        cin >> left >> right >> coins;

        b = one_b = left;
        e = one_e = right;
        one_ans = left_ans = right_ans = coins;

        cout << coins << '\n';

        // for rests
        for(i = 1; i < n; ++i) {
            cin >> left >> right >> coins;

            if(left == b)
                left_ans = min(left_ans, coins);
            else if(left < b) {
                b = left;
                left_ans = coins;
            }

            if(right == e)
                right_ans = min(right_ans, coins);
            else if(right > e) {
                e = right;
                right_ans = coins;
            }

            // for one
            if(left <= one_b && right >= one_e) {
                
                if(left < one_b || right > one_e)
                    one_ans = coins;
                else
                    one_ans = min(one_ans, coins);

                one_b = left;
                one_e = right;
            }

            // processing for one
            if(b == one_b && e == one_e)
                cout << min(one_ans, left_ans+right_ans) << '\n';
            else
                cout << (left_ans+right_ans) << '\n';
        }

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