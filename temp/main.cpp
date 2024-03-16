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
    int n;
    vector <int> freq;

    bool check(int k)
    {
        int i;
        vector <int> fre;

        for(i = 0; i <= k; ++i)
            fre.push_back(freq[i]);

        sort(fre.begin(), fre.end());
        int need = 1;

        for(i = 0; i <= k; ++i) {
            if(fre[i] < need)
                return false;

            ++need;
        }

        return true;
    }
public:
    void solve()
    {
        int i, ai;

        cin >> n;

        freq.resize(n+5);

        for(i = 0; i < n; ++i) {
            cin >> ai;
            ++freq[ai];
        }

        int low = 0, high = n, mid;

        while(low <= high) {
            mid = (low + high) / 2;

            if(check(mid))
                low = mid+1;
            else
                high = mid-1;
        }

        if(freq[low] && low != 1)
            ++low;

        cout << max(0, low) << '\n';

        freq.clear();        

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