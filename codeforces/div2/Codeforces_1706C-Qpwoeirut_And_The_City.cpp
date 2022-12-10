/**
 * Codeforces Round #809 (Div. 2)
 * Problem C - Qpwoeirut And The City
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;

typedef long long int ll;

#define LIM 100001

class Solution
{
    int n, height[LIM];
    ll front[LIM+1], back[LIM+1];

    inline int cost(int idx)
    {
        int fin = max(height[idx], max(height[idx-1], height[idx+1]) + 1);

        return fin - height[idx];        
    }
public:
    ll solve()
    {
        int i;
        ll ans;

        cin >> n;

        for(i = 1; i <= n; ++i)
            cin >> height[i];

        if(n & 1)
        {
            ans = 0;
            for(i = 2; i < n; i += 2)
                ans += cost(i);
        }
        else
        {
            // front pattern
            front[0] = 0;
            for(i = 2; i < n; i += 2)
                front[i] = cost(i) + front[i-2];
            
            // back pattern
            back[n+1] = 0;
            for(i = n-1; i > 0; i -= 2)
                back[i] = cost(i) + back[i+2];

            // generating ans
            ans = back[3];
            for(i = 3; i < n; i += 2)
                ans = min(ans, front[i-1] + back[i+2]);
        }

        return ans;
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
        cout << sol.solve() << '\n';
 
    return 0;
}