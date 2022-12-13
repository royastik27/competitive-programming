/**
 * Codeforces Round #291 (Div. 2)
 * Problem B - Han Solo and Lazer Gun
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>
 
using namespace std;
 
#define INF 20001
 
class Solution
{
 
public:
    int solve()
    {
        int n, x0, y0, x, y, denom;
        map <double, int> mp;
 
        cin >> n >> x0 >> y0;
 
        while(n--)
        {
            cin >> x >> y;
            
            denom = y - y0;

            ++mp[denom ? double(x-x0) / (y-y0) : INF];
        }
 
        return mp.size();
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