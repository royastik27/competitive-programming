/**
* Codeforces Round 218 (Div. 2)
* Problem C - Hamburgers
* TIME: 15 ms
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
    string str;
    int nB, nS, nC, pB, pS, pC, cntB, cntS, cntC;
    ll r;
public:
    void solve()
    {
        int i, cost, need;

        cin >> str;

        cin >> nB >> nS >> nC >> pB >> pS >> pC >> r;

        n = str.length();
        cntB = cntS = cntC = 0;

        for(i = 0; i < n; ++i) {
            if(str[i] == 'B')
                ++cntB;
            else if(str[i] == 'S')
                ++cntS;
            else
                ++cntC;
        }

        ll ans = 0;
        while((nB && cntB) || (nS && cntS) || (nC && cntC)) {

            cost = 0;

            if(nB < cntB) {
                need = cntB - nB;
                cost += need * pB;
            }
            
            if(nS < cntS) {
                need = cntS - nS;
                cost += need * pS;
            }

            if(nC < cntC) {
                need = cntC - nC;
                cost += need * pC;
            }

            if(!cost) {
                // we have all for one burger

                nB = max(0, nB - cntB);
                nS = max(0, nS - cntS);
                nC = max(0, nC - cntC);

                ++ans;
            }
            else if(cost > r){
                r = 0;
                break;
            }
            else {
                nB = max(0, nB - cntB);
                nS = max(0, nS - cntS);
                nC = max(0, nC - cntC);

                r -= cost;

                ++ans;
            }
        }

        // preparing a burger with bought ingrediants
        cost = cntB * pB + cntS * pS + cntC * pC;

        ans += r / cost;

        cout << ans << '\n';

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