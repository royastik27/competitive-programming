/**
 * Codeforces Round #654 (Div. 2)
 * Problem C - A Cookie for You
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

typedef long long int ll;

class Solution {
    
public:
    bool solve()
    {
        ll vanilla, choco, first, second;

        cin >> choco >> vanilla >> first >> second;

        if(choco + vanilla < first + second)
            return false;

        if(choco == vanilla && vanilla >= second)
            return true;
        else if(min(choco, vanilla) >= second)
            return true;

        return false;
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
        if(sol.solve()) cout << "Yes\n";
        else cout << "No\n";
    
    return 0;
}