/**
* [name]
* Problem 
* TIME: 
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
    int n, c;
public:
    void solve()
    {
        int i, ai;

        cin >> n >> c;

        ll total = ll(c+1)*(c+2) / 2, minus = 0;
        int even, odd;

        even = odd = 0;

        for(i = 0; i < n; ++i) {
            cin >> ai;

            minus += (ai+1) / 2;
            minus += c - ai + 1;

            if(ai & 1)
                minus -= odd;
            else minus -= even;

            if(ai & 1) ++odd;
            else ++even;
        }

        cout << (total - minus) << '\n';

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