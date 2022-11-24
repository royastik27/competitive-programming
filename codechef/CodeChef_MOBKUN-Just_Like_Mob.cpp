/**
 * CodeChef MOBKUN - Just Like Mob!
 * TIME: 0.03s
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution{

public:
    bool solve()
    {
        int n, m, k, x, due;

        cin >> n >> m >> k >> x;

        due = x % (k*n + m);
        
        return !due || due > (k-1)*n;
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