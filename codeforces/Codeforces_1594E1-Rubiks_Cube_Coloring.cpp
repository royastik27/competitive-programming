/**
 * Codeforces Round #747 (Div. 2)
 * Problem E1 - Rubik's Cube Coloring (easy version)
 * TIME: 0 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>
 
using namespace std;

typedef long long int ll;

#define MOD 1000000007
 
class Solution {

    int power(int base, ll p)
    {
        if(p == 0) return 1;

        if(p & 1)
            return (ll)base * power(base, p-1) % MOD;
        else return power((ll)base*base % MOD, p/2);
    } 

public:
    int solve()
    {
        int k;
        cin >> k;

        return (ll)power(4, (ll)pow(2, k) - 2) * 6 % MOD;
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