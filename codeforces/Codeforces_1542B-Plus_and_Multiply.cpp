/**
 * Codeforces Round #729 (Div. 2)
 * Problem B - Plus and Multiply
 * Time: 186 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, a, b;
    long long int x;
    bool isPossible;

    cin >> TC;

    while(TC--) {
        cin >> n >> a >> b;

        isPossible = false;        

        if(a == 1)
            isPossible = ((n-1) % b == 0);
        else {
            x = 1;
            while(n >= x) {
                if((n-x) % b == 0) {
                    isPossible = true;
                    break;
                }

                x *= a;
            }
        }

        if(isPossible) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
