/**
 * Codeforces Round #341 (Div. 2)
 * Problem B - Wet Shark and Bishops
 * TIME: 109 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>

using namespace std;

class Solution {

public:
    int solve()
    {
        int n, i, j, ans = 0;
        map <int, int> main;
        map <int, int> second;
        map <int, int>::iterator it;

        cin >> n;

        while(n--)
        {
            cin >> i >> j;
            ++main[i-j];
            ++second[i+j];
        }

        for(it = main.begin(); it != main.end(); ++it)
            ans += it->second * (it->second-1) / 2;
        
        for(it = second.begin(); it != second.end(); ++it)
            ans += it->second * (it->second-1) / 2;

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
