/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef pair <int, int> pii;

// #define LIM 200010
#define LIM 2010

class Solution
{
    int tree[LIM * 4], depth[LIM * 4];
    vector <pii> inp;

    int insert(int val, int node = 1)
    {
        cout << "Calling Node: " << node << "\t value: " << tree[node] << '\n';
        ++depth[node];

        if(tree[node] == INT_MAX) {
            tree[node] = val;
            return 0;
        }

        int left = node*2, right = left + 1;

        if(val > tree[node])
            return insert(val, right);
        else
            return 1 + depth[right] + insert(val, left);
    }
public:
    void solve()
    {
        int n, i, lim;
        ll ans;

        cin >> n;

        inp.resize(n);

        for(i = 0; i < n; ++i)
            cin >> inp[i].first >> inp[i].second;

        sort(inp.begin(), inp.end());

        // initializing tree
        lim = 4*n;
        for(i = 1; i <= lim; ++i) {
            tree[i] = INT_MAX;
            depth[i] = 0;
        }

        ans = 0;
        for(i = 0; i < n; ++i) {
            cout << "\nFor " << inp[i].second << '\n';
            ans += insert(inp[i].second);
        }

        cout << ans << '\n';

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