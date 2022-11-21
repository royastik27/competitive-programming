/**
 * Codeforces Round #441 (Div. 2, by Moscow Team Olympiad)
 * Problem B - Divisiblity of Differences
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

#define LIM 100000

class Solution{

public:
    void solve()
    {
        vector <int> cong[LIM];
        int n, k, m, num, rem, ans = -1;

        cin >> n >> k >> m;

        while(n--)
        {
            cin >> num;
            rem = num % m;

            cong[rem].push_back(num);

            if(cong[rem].size() >= k)
                ans = rem;
        }

        if(ans == -1)
            cout << "No\n";
        else
        {
            cout << "Yes\n";
            for(m = 0; m < k; ++m)
                cout << cong[ans][m] << ' ';
            cout << '\n';
        }
        
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