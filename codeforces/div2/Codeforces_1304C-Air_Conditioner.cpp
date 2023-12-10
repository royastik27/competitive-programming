/**
* Codeforces Round 620 (Div. 2)
* Problem C - Air Conditioner
* TIME: 62 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    void solve()
    {
        int n, i, currMn, currMx, mn, mx, time, prevTime, inc;
        bool possible;

        cin >> n >> currMn;

        currMx = currMn;
        possible = true;
        prevTime = 0;

        for(i = 0; i < n; ++i)
        {
            cin >> time >> mn >> mx;

            inc = time - prevTime;
            prevTime = time;

            if(possible) {
                currMn -= inc;
                currMx += inc;

                if(mn > currMx || mx < currMn)
                    possible = false;
                else {
                    currMn = max(currMn, mn);
                    currMx = min(currMx, mx);
                }
            }
        }

        cout << (possible ? "YES\n" : "NO\n");

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