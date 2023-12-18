/**
* Codeforces Global Round 8
* Problem C - Even Picture
* TIME: 15 ms
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
        int n, i, x, y;

        cin >> n;

        x = y = 0;
        
        cout << (4 + 3*n) << '\n';

        cout << x << ' ' << y << '\n';

        for(i = 0; i <= n; ++i) {            
            cout << x << ' ' << y+1 << '\n';
            cout << x+1 << ' ' << y << '\n';
            cout << x+1 << ' ' <<  y+1 << '\n';
            ++x;
            ++y;
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