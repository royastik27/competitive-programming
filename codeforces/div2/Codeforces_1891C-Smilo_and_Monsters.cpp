/**
* Codeforces Round 907 (Div. 2)
* Problem C - Smilo and Monsters
* TIME: 78 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

class Solution
{
    vector <int> a;
public:
    void solve()
    {
        int n, i, j, compVar, need;
        ll ans;

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> j;

            a.push_back(j);
        }

        sort(a.begin(), a.end(), greater<int>());

        i = 0; j = n-1;
        ans = compVar = 0; 
        while(i <= j)
        {
            if(i == j)
            {
                if(a[i] + compVar == 1)
                    ++ans;
                else
                    ans += ceil((a[i] + compVar) / 2.0) + 1;

                break;
            }
            else if(compVar < a[i])
            {
                need = min(a[j], a[i] - compVar);

                if(!(a[j] -= need))
                    --j;

                compVar += need;
            }
            else
            {
                ans += a[i] + 1;
                ++i;
                compVar = 0;
            }
        }

        cout << ans << '\n';

        a.clear();

        return;
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
        sol.solve();

    return 0;
}