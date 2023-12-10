/**
* Codeforces Round 605 (Div. 3)
* Problem D - Remove One Element
* TIME: 78 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define LIM 200000

class Solution
{
    int a[LIM], forw[LIM], back[LIM];
public:
    Solution() { forw[0] = 1; }

    void solve()
    {
        int n, i, mx;

        cin >> n;

        cin >> a[0];
        mx = 0;

        for(i = 1; i < n; ++i)
        {
            cin >> a[i];

            forw[i] = a[i] > a[i-1] ? forw[i-1]+1 : 1;

            mx = max(mx, forw[i]);
        }

        back[n-1] = 1;
        for(i = n-2; i >= 0; --i)
            back[i] = a[i] < a[i+1] ? back[i+1]+1 : 1;

        for(i = 2; i+1 < n; ++i)
        {
            if(a[i-1] < a[i+1])
                mx = max(mx, forw[i-1] + back[i+1]);
        }

        cout << mx << '\n';

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