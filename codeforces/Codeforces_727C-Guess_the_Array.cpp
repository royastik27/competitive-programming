/**
 * Technocup 2017 - Elimination Round 1 (Unofficially Open for Everyone, Rated for Div. 2)
 * Problem C - Guess the Array
 * Time: 62 ms	
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
        int ab, bc, ac, a_c, a, i;

        // GENERATING FIRST THREE
        cout << "? " << 1 << ' ' << 2 << endl;
        cin >> ab;
        cout << "? " << 2 << ' ' << 3 << endl;
        cin >> bc;
        cout << "? " << 1 << ' ' << 3 << endl;
        cin >> ac;

        a_c = ab - bc;
        a = (a_c + ac) / 2;
        
        ans.push_back(a);
        ans.push_back(ab - a);
        ans.push_back(ac - a);

        // GENERATING OTHERS
        for(i = 4; i <= n; ++i)
        {
            cout << "? " << 1 << ' ' << i << endl;
            cin >> ab;
            ans.push_back(ab - a);
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