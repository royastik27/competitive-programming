/**
 * Codeforces Round #345 (Div. 2)
 * Problem C - Watchmen
 * TIME: 420 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    ll solve()
    {
        int n, i, j, r, c, b;
        ll ans = 0;
        map <int, int> row, col;
        map < pair <int, int>, int > rowCol;

        cin >> n;

        while(n--)
        {
            cin >> i >> j;

            r = row[i]++;
            c = col[j]++;
            b = rowCol[{ i, j }]++;
            
            ans += r + c - b;
        }        

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