/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long int ll;

class Solution
{
    vector <int> a, forw, back;
public:
    void solve()
    {
        int n, i, curr, plus2, minus2;
        ll ans;

        cin >> n;
        
        a.resize(n);
        forw.resize(n+2);
        back.resize(n+2);
        
        for(i = 0; i < n; ++i) {
            cin >> a[i];
            forw[i] = back[i] = 0;
        }

        forw[n] = back[n] = forw[n+1] = back[n+1] = 0;

        // backward array
        for(i = n-1; i > 0; --i)
            ++back[a[i]];

        ans = 0;
        for(i = 1; i < n-1; ++i)
        {
            curr = a[i];
            minus2 = max(curr-2, 0);
            plus2 = min(curr+2, n+1);

            ++forw[a[i-1]];
            --back[curr];

            // as max
            ans += ll(forw[minus2]+forw[curr-1]+forw[curr]) * (back[minus2]+back[curr-1]+back[curr]);

            // as min
            ans += ll(forw[plus2]+forw[curr+1]+forw[curr]) * (back[plus2]+back[curr+1]+back[curr]);

            // duplicates of curr - curr - curr
            ans -= (ll)forw[curr] * back[curr];

            // as medium
            ans += (ll)forw[curr+1] * back[curr-1] + (ll)forw[curr-1] * back[curr+1];
        }

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