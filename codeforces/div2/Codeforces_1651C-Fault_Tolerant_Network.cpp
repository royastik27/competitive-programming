/**
* Educational Codeforces Round 124 (Rated for Div. 2)
* Problem C - Fault-tolerant Network
* TIME: 109 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
    vector <int> a[2];
    vector <ll> var;

    int abs(int n)
    {
        return (n < 0) ? 0-n : n;
    }

    int find_best(int row, int idx)
    {
        int val = a[row][idx];
        int src_row = row ^ 1;

        int mn = INT_MAX, i;

        for(i = 0; i < n; ++i)
            mn = min(mn, abs(a[src_row][i]-val));

        return mn;
    }

    int cost(int idx1, int idx2)
    {
        return abs(a[0][idx1]-a[1][idx2]);
    }
public:
    void solve()
    {
        int i;

        cin >> n;

        a[0].resize(n);
        a[1].resize(n);

        for(i = 0; i < n; ++i)
            cin >> a[0][i];        
        for(i = 0; i < n; ++i)
            cin >> a[1][i];

        ll b11 = find_best(0, 0);
        ll b1n = find_best(0, n-1);
        ll b21 = find_best(1, 0);
        ll b2n = find_best(1, n-1);

        var.push_back(cost(0, 0) + cost(n-1, n-1));
        var.push_back(cost(0, 0) + b1n + b2n);
        var.push_back(cost(n-1, n-1) + b11 + b21);

        var.push_back(cost(0, n-1) + cost(n-1, 0));
        var.push_back(cost(0, n-1) + b21 + b1n);
        var.push_back(cost(n-1, 0) + b11 + b2n);

        var.push_back(b11 + b1n + b21 + b2n);

        cout << *min_element(var.begin(), var.end()) << '\n';

        var.clear();

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