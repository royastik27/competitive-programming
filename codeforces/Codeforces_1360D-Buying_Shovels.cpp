/**
 * Codeforces Round #644 (Div. 3)
 * Problem D - Buying Shovels
 * Time: 31 ms
 * AUTHOR: Astik Roy
 **/

#include <iostream>
#include <cmath>

using namespace std;

#define LIM 1000000000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC, sum, type, ans, res, i, root;

    cin >> TC;

    while(TC--)
    {
        cin >> sum >> type;

        if(type >= sum) ans = 1;
        else
        {
            ans = LIM;
            root = sqrt(sum);

            for(i = 2; i <= type && i <= root; ++i)
            {
                if(sum % i == 0)
                {
                    res = sum / i;

                    if(res <= type)
                        ans = min(ans, i);
                    else ans = min(ans, res);
                }
            }

            if(ans == LIM) ans = sum;
        }

        cout << ans << '\n';
    }

    return 0;
}
