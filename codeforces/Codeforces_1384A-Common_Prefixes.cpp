/**
* Codeforces Round #659 (Div. 2)
* Problem A - Common Prefixes
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, lcp;
    char res[52];
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> n;

        // reset
        for(i = 0; i < 51; ++i)
            res[i] = 'a';
        res[i] = '\0';

        cout << res << '\n';

        for(i = 0; i < n; ++i) {
            cin >> lcp;

            res[lcp] = (res[lcp] == 'a') ? 'b' : 'a';

            cout << res << '\n';
        }
    }

    return 0;
}
