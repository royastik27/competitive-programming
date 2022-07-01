/**
 * 2020 ICPC, COMPFEST 12, Indonesia Multi-Provincial Contest (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
 * Problem F - Flamingoes of Mystery
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    void solve(int n)
    {
        vector <int> ans;
        int abc, ab, bc, i;

        // GENERATING FIRST THREE
        cout << "? " << 1 << ' ' << 3 << endl;
        cin >> abc;
        cout << "? " << 1 << ' ' << 2 << endl;
        cin >> ab;
        cout << "? " << 2 << ' ' << 3 << endl;
        cin >> bc;
        
        ans.push_back(abc - bc);
        ans.push_back(ab - ans[0]);
        ans.push_back(bc - ans[1]);

        // GENERATING OTHERS
        for(i = 4; i <= n; ++i)
        {
            cout << "? " << i - 1 << ' ' << i << endl;
            cin >> ab;
            ans.push_back(ab - ans[i - 2]);
        }        
        
        cout << "! ";
        for(i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    Solution sol;
    int n;

    cin >> n;
    sol.solve(n);
    
    return 0;
}