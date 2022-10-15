/**
 * Codeforces Round #827 (Div. 4)
 * Problem D - Coprime
 * TIME: 702 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>
 
using namespace std;
 
class Solution {
    map <int, int> mp;
    map <int, int>::iterator it, it2;
 
    int gcd(int a, int b)
    {
        if(b == 0) return a;
 
        return gcd(b, a%b);
    }
public:
    int solve()
    {
        int n, i, el;
 
        cin >> n;
 
        for(i = 1; i <= n; ++i)
        {
            cin >> el;
            if(mp[el] < i) mp[el] = i;
        }
        
        int mx = -1, sum;
 
        for(it = mp.begin(); it != mp.end(); ++it)
        {
            for(it2 = mp.begin(); it2 != mp.end(); ++it2)
            {
                if(gcd(it->first, it2->first) == 1)
                {
                    sum = it->second + it2->second;
 
                    if(sum > mx) mx = sum;
                }
            }
        }
 
        mp.clear();
        
        return mx;
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