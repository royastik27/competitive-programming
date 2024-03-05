/**
* Codeforces Round 835 (Div. 4)
* Problem F - Quests
* TIME: 78 ms
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
    int n, d;
    ll c;
    vector <int> a;

    bool check(int k)
    {
        int i, j, inc, lim;
        ll coins = 0;

        inc = k+1;
        lim = min(inc, (int)a.size());

        for(i = 0; i < lim; ++i) {
            for(j = i; j < d; j += inc) {
                coins += a[i];
            }
        }

        return (coins >= c);

    }

    int UB_k(int low, int high)
    {
        int mid;

        while(low <= high)
        {
            mid = (low+high) / 2;

            if(check(mid))
                low = mid+1;
            else
                high = mid-1;
        }

        return low;
    }
public:
    void solve()
    {
        int i;

        cin >> n >> c >> d;

        a.resize(n);

        for(i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end(), greater<int>());

        int UB = UB_k(0, d-1);

        if(UB == 0)
            cout << "Impossible\n";
        else if(UB == d)
            cout << "Infinity\n";
        else
            cout << (UB-1) << '\n';

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