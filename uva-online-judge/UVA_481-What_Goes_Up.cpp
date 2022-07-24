/**
 * UVA 481 - What Goes Up
 * Implemented LIS without learning the algo
 * RANK: 1131 out of 9302
 * TIME: 0.010 sec
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solve()
    {
        int el, sz, i;
        vector <int> vec;

        // INPUT
        while(cin >> el)
            vec.push_back(el);
        
        sz = vec.size();

        vector <int> par(sz), idx(sz+1, 0), lis;
        vector <int>::iterator it;
        int LB;

        // GENERATING RESULT
        idx[0] = -1;

        for(i = 0; i < sz; ++i)
        {
            it = lower_bound(lis.begin(), lis.end(), vec[i]);
            LB = it - lis.begin();

            if(it == lis.end()) lis.push_back(vec[i]);
            else                lis[LB] = vec[i];

            idx[LB + 1] = i;
            par[i] = idx[LB];
        }

        // GETTING RESULT
        el = idx[lis.size()];

        lis.clear();
        while(el != -1)
        {
            lis.push_back(vec[el]);
            el = par[el];
        }

        // PRINTING RESULT
        sz = lis.size();
        cout << sz << "\n-\n";
        for(i = sz - 1; i >= 0; --i)
            cout << lis[i] << '\n';

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    sol.solve();
    
    return 0;
}