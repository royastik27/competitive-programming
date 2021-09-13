/**
 * Codeforces Round #629 (Div. 3)
 * Problem A - Divisibility Problem
 * Time: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, a, b;

    cin >> TC;

    while(TC--) {
        cin >> a >> b;

        cout << (int)ceil((double)a / b) * b - a << '\n';
    }

    return 0;
}
