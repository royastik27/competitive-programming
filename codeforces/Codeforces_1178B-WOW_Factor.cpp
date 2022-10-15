/**
 * Codeforces Global Round 4
 * Problem B - WOW Factor
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;

#define LIM 1000000
 
class Solution {
    int forw[LIM], back[LIM];
public:
    long long int solve()
    {
        long long int ans = 0;
        string str;
        int sz, i;

        cin >> str;
        sz = str.size();

        forw[0] = 0;
        for(i = 1; i < sz; ++i)
            if(str[i] == 'v' && str[i-1] == 'v')
                forw[i] = forw[i-1] + 1;
            else forw[i] = forw[i-1];

        back[sz - 1] = 0;
        for(i = sz - 2; i >= 0; --i)
            if(str[i] == 'v' && str[i+1] == 'v')
                back[i] = back[i+1] + 1;
            else back[i] = back[i+1];

        for(i = 2; i < sz; ++i)
            if(str[i] == 'o')
                ans += (long long int)forw[i] * back[i];
        
        return ans;
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