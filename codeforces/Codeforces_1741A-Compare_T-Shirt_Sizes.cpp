/**
 * Codeforces Round #826 (Div. 3)
 * Problem A - Compare T-Shirt Sizes
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;
 
#define LIM 
 
class Solution {
    int hash(char ch)
    {
        switch(ch)
        {
            case 'S':
                return 0;
            case 'M':
                return 1;
            default:
                return 2;
        }
    }
    
public:
    void solve()
    {
        string one, two;
 
        cin >> one >> two;
 
        int h1 = hash(one[one.size() - 1]);
        int h2 = hash(two[two.size() - 1]);
 
        if(h1 > h2) cout << ">\n";
        else if(h1 < h2) cout << "<\n";
        else
        {
            int x1, x2;
            for(x1 = 0; one[x1] == 'X'; ++x1);
            for(x2 = 0; two[x2] == 'X'; ++x2);
 
            if(h1 == 0)
            {
                if(x1 < x2) cout << ">\n";
                else if(x1 > x2) cout << "<\n";
                else cout << "=\n";
            }
            else
            {
                if(x1 < x2) cout << "<\n";
                else if(x1 > x2) cout << ">\n";
                else cout << "=\n";
            }
        }        
        
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