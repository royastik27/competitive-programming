/**
 * Codeforces Round #615 (Div. 3)
 * Problem C - Product of Three Numbers
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution{
    vector <int> res;
public:
    void solve()
    {
        int n, root, i;
        
        cin >> n;

        root = sqrt(n);

        for(i = 2; res.size() < 2 && i <= root; ++i)
        {
            if(n % i == 0)
            {
                res.push_back(i);
                n /= i;
            }
        }

        if(res.size() == 2 && n > 1 && n != res[0] && n != res[1])
            cout << "YES\n" << res[0] << ' ' << res[1] << ' ' << n << '\n';
        else cout << "NO\n";

        res.clear();

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