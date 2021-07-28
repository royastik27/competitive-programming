/**
 * Codeforces Round #493 (Div. 2)
 * Problem A - Balloons
 * Time: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 10

int main()
{
    ios_base::sync_with_stdio(0);

    int n, ara[LIM], sum, last2, last1;
    register int i;

    cin >> n;

    if(n == 1) {
        cin >> ara[0];
        cout << "-1\n";
    }
    else {
        sum = 0;
        for(i = 0; i < n - 2; ++i) {
            cin >> ara[i];
            sum += ara[i];
        }

        cin >> ara[n-2] >> ara[n-1];

        if(sum + ara[n-2] == ara[n-1]) {
            if(n == 2) cout << "-1\n";
            else {
                cout << n-2 << '\n';
                for(i = 1; i <= n-2; ++i)
                    cout << i << ' ';
                cout << '\n';
            }
        }
        else {
            cout << n-1 << '\n';
            for(i = 1; i <= n-1; ++i)
                cout << i << ' ';
            cout << '\n';
        }
    }

    return 0;
}
