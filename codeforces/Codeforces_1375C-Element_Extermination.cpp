/**
 * Codeforces Global Round 9
 * Problem C - Element Extermination
 * TIME: 78 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution
{
    int n, first, last;
public:
    bool solve()
    {
        cin >> n >> first;

        --n;
        while(n--)
            cin >> last;

        return last > first;
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
        if(sol.solve()) cout << "YES\n";
        else cout << "NO\n";
 
    return 0;
}