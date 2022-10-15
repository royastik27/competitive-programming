/**
 * Codeforces Round #827 (Div. 4)
 * Problem A - Sum
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;
 
#define LIM 
 
class Solution {
    
public:
    void solve()
    {
        int a, b, c;

        cin >> a >> b >> c;

        if(a+b == c || b+c == a || c+a == b) cout << "YES\n";
        else cout << "NO\n";
        
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