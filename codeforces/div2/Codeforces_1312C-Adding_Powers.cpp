/**
 * Educational Codeforces Round 83 (Rated for Div. 2)
 * Problem C - Adding Powers
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;

typedef long long int ll;

#define LIM 30

class Solution
{
    int n, i, k;
    ll mx, term, a[LIM];
public:
    bool solve()
    {
        cin >> n >> k;

        mx = 0;
        for(i = 0; i < n; ++i)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        term = 1;
        while(term <= mx)
            term *= k;
        term /= k;

        while(term)
        {
            for(i = 0; i < n; ++i)
            {
                if(a[i] >= term)
                {
                    a[i] -= term;
                    break;
                }
            }

            term /= k;
        }

        for(i = 0; i < n; ++i)
            if(a[i]) return false;
        
        return true;
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
        if(sol.solve()) cout << "YES\n";
        else cout << "NO\n";
 
    return 0;
}