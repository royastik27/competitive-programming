/**
 * Codeforces Round #535 (Div. 3)
 * Problem C - Nice Garland
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{

public:
    void solve()
    {
        int n;
        cin >> n;
        vector <int> vec(n);

        for(int i = 0; i < vec.size(); ++i)
            cout << vec[i] << ' ';
        cout << '\n';
        
        
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