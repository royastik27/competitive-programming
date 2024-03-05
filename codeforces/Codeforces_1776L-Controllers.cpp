/**
* SWERC 2022-2023 - Online Mirror
* Problem L - Controllers
* TIME: 78 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
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
    int n, nP, nM;
    string str;

    bool go(int a, int b)
    {
        int A, B, d, nA, nB, mxPM, mnPM, m;

        A = min(a, b);
        B = max(a, b);

        d = __gcd(a, b);

        nA = B / d;
        nB = A / d;

        mxPM = max(nP, nM);
        mnPM = min(nP, nM);

        if((mxPM - mnPM) % (nA - nB) != 0)
            return false;

        m = (mxPM - mnPM) / (nA - nB);

        if(mxPM < (ll)m*nA || mnPM < (ll)m*nB)
            return false;

        return true;
    }
public:
    void solve()
    {
        int q, i, a, b;
        bool ans;
        
        cin >> n >> str >> q;

        nP = nM = 0;
        for(i = 0; i < n; ++i) {
            if(str[i] == '+') ++nP;
            else ++nM;
        }

        while(q--) {
            cin >> a >> b;

            if(nP == nM)
                ans = true;
            else if(a == b)
                ans = false;
            else
                ans = go(a, b);

            cout << (ans ? "YES\n" : "NO\n");     
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    sol.solve();

    return 0;
}