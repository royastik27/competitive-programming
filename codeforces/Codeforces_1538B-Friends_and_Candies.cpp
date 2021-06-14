/**
* Codeforces Round #725 (Div. 3)
* Problem B - Friends and Candies
* Time: 93 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 200000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, ara[LIM], sum, res;
    double val;
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> n;

        sum = 0;
        for(i = 0; i < n; ++i) {
            cin >> ara[i];
            sum += ara[i];
        }

        val = (double) sum / n;

        if(val > (int)val)
            res = -1;
        else {
            res = 0;
            for(i = 0; i < n; ++i) {
                if(ara[i] > val) ++res;
            }
        }
        cout << res << '\n';
    }

    return 0;
}
