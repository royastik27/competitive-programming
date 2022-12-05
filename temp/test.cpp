/**
 * Codeforces Round #535 (Div. 3)
 * Problem C - Nice Garland
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{

public:
    void solve()
    {
        map <int, int> s;

        s.insert({ 1, 2 });
        s.insert({ 1, 2 });
        s.insert({ 2, 5 });
        s.insert({ 1, 3 });

        auto it = s.lower_bound(1);

        cout << it->first << ' ' << it->second << '\n';
        
        
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    sol.solve();

    return 0;
}