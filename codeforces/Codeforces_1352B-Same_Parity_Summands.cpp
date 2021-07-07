/**
 * Codeforces Round #640 (Div. 4)
 * Problem B - Same Parity Summands
 * Time: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, k;
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> n >> k;

        if(k > n) {
            cout << "NO\n";
            continue;
        }

        if(n & 1) { // if n is odd
            if(k & 1) { // if k is odd
                cout << "YES\n";
                --k;
                for(i = 0; i < k; ++i)
                    cout << 1 << ' ';
                cout << n - k << '\n';
            } else cout << "NO\n";
        }
        else {  // if n is even
            if(!(k & 1)) { // if k is even
                cout << "YES\n";
                --k;
                for(i = 0; i < k; ++i)
                    cout << 1 << ' ';
                cout << n - k << '\n';
            }
            else if(k <= n / 2) {
                cout << "YES\n";
                --k;
                for(i = 0; i < k; ++i)
                    cout << 2 << ' ';
                cout << n - k*2 << '\n';
            }
            else cout << "NO\n";
        }
    }

    return 0;
}
