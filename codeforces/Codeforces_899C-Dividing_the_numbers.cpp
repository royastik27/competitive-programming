/**
 * Codeforces Round #452 (Div. 2)
 * Problem C - Dividing the numbers
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int ll;

class Solution{
    
public:
    void solve()
    {
        int n, i, sz, curr, sum = 0;
        bool one = true;
        vector <int> ans;
    
        cin >> n;

        curr = n;

        do
        {
            ans.push_back(curr);
            sum += curr;

            if(one) { curr -= 3; one = false; }
            else { curr -= 1; one = true; }

        } while (curr > 0);

        cout << abs((ll)n * (n+1) / 2 - 2*sum) << '\n';

        sz = ans.size();
        cout << sz << ' ';
        for(i = 0; i < sz; ++i) cout << ans[i] << ' ';
        cout << '\n';

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