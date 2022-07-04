/**
 * Codeforces Round #644 (Div. 3)
 * Problem E - Polygon
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 50

class Solution
{
    char str[LIM][LIM];
    public:
    bool solve(int n)
    {
        int i, j;

        // INPUT
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                cin >> str[i][j];

        // PROCESSING
        --n;
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                if(str[i][j] == '1')
                {
                    if(str[i+1][j] == '0' && str[i][j+1] == '0')
                        return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    int TC, n;

    cin >> TC;

    while(TC--)
    {
        cin >> n;
        if(sol.solve(n)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}