/**
 * Codeforces Round #799 (Div. 4)
 * Problem F - 3SUM
 * TIME: 77 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

class Solution
{
    int mp[10], need[10];
public:
    bool solve()
    {
        int n, i, j, k, sum;
        memset(mp, 0, sizeof(mp));

        cin >> n;

        while(n--)
        {
            cin >> i;
            ++mp[i % 10];
        }

        for(i = 0; i < 10; ++i)
        {
            for(j = 0; j < 10; ++j)
            {
                memset(need, 0, sizeof(need));
                for(k = 0; k < 10; ++k)
                {
                    sum = i + j + k;

                    if(sum % 10 == 3)
                    {
                        ++need[i];
                        ++need[j];
                        ++need[k];

                        if(mp[i] >= need[i] && mp[j] >= need[j] && mp[k] >= need[k])
                            return true;
                    }
                }
            }
        }        
        
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
        cout << (sol.solve() ? "YES\n" : "NO\n");

    return 0;
}