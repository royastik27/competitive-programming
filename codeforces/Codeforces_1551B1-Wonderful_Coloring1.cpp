/**
 * Codeforces Round #734 (Div. 3)
 * Problem B1 - Wonderful Coloring - 1
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, m[26], distinct, res;
    char str[51];
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> str;

        memset(m, 0, sizeof(m));

        for(i = 0; str[i] != '\0'; ++i) {
            ++m[(int)str[i]-'a'];
        }

        distinct = res = 0;
        for(i = 0; i < 26; ++i) {
            if(m[i] == 1) ++distinct;
            else
                res += (m[i] > 0);
        }

        res += distinct / 2;

        cout << res << '\n';
    }

    return 0;
}
