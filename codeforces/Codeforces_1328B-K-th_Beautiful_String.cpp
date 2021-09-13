/**
 * Codeforces Round #629 (Div. 3)
 * Problem B - K-th Beautiful String
 * Time: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 100001

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, k, r1, r2;
    long long int a, temp;
    char res[LIM];

    for(register int i = 0; i < LIM; ++i) res[i] = 'a';

    cin >> TC;

    while(TC--) {
        cin >> n >> k;

        // finding two indices for 'b'
        r1 = 1;
        a = temp = 1;
        while(a <= k) {
            a += temp;
            ++r1;
            ++temp;
        }

        a -= --temp;
        r1 = n - r1;
        r2 = n - (k - a) - 1;

        // producing the result
        res[r1] = res[r2] = 'b';
        res[n] = '\0';
        cout << res << '\n';
        res[r1] = res[r2] = 'a';
        res[n] = 'a';
    }

    return 0;
}
