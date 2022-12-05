/**
 * Codeforces Round #653 (Div. 3)
 * Problem E1 - Reading Books (easy version)
 * TIME: 124 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{

public:
    int solve()
    {
        int n, k, time, ans = 0, i, j;
        bool al, bo;
        vector <int> both, alice, bob;

        cin >> n >> k;

        while(n--)
        {
            cin >> time >> al >> bo;

            if(al && bo)
                both.push_back(time);
            else if(al)
                alice.push_back(time);
            else if(bo)
                bob.push_back(time);
        }

        sort(both.begin(), both.end());
        sort(alice.begin(), alice.end());
        sort(bob.begin(), bob.end());

        i = j = 0;
        
        while(k && i < both.size() && j < alice.size() && j < bob.size())
        {
            if(both[i] < alice[j] + bob[j])
            {
                ans += both[i];
                ++i;
            }
            else { ans += alice[j]+bob[j]; ++j; }

            --k;
        }

        while(k && i < both.size())
        {
            ans += both[i];
            ++i;
            --k;
        }

        while(k && j < alice.size() && j < bob.size())
        {
            ans += alice[j]+bob[j];
            ++j;
            --k;
        }

        return k ? -1 : ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    cout << sol.solve() << '\n';

    return 0;
}
