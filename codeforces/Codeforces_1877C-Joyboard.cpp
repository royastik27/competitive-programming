/**
* Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)
* Problem C - Joyboard
* TIME: 46 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    void solve()
    {
        int n, m, k, ans;

        cin >> n >> m >> k;

        if(k == 1)
            ans = 1;
        else if(k == 2)
            ans = min(n-1, m) + m / n;
        else if(k == 3)
        {
            if(m < n+1)
                ans = 0;
            else
                ans = (m - n) - m / n + 1;
        }
        else ans = 0;

        cout << ans << '\n';        

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