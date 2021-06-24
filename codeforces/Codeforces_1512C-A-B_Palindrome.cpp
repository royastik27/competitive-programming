/**
* Codeforces Round #713 (Div. 3)
* Problem C - A-B Palindrome
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 400001

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, a, b, c0, c1, hl, cq, len;
    char str[LIM];
    register int i, j;

    cin >> TC;

    while(TC--) {
        cin >> a >> b >> str;

        c0 = c1 = 0;

        len = a + b;
        hl = len / 2;

        for(i = 0, j = len - 1; i < hl; ++i, --j) {

            cq = 0;
            if(str[i] == '?') ++cq;
            if(str[j] == '?') ++cq;

            if(cq == 2) // both are ?
                continue;
            else if(cq == 0) {  // none of them is ?
                if(str[i] != str[j]) {
                    c0 = c1 = LIM;
                    break;
                }
            }
            else if(str[i] == '?')
                str[i] = str[j];
            else  // str[j] == '?'
                str[j] = str[i];

            str[j] == '0' ? c0 += 2 : c1 += 2;
        }

        a -= c0;
        b -= c1;

        for(i = 0, j = len - 1; i < hl; ++i, --j) {
            if(str[i] == '?') {
                if(a > 1) {
                    str[i] = str[j] = '0';
                    a -= 2;
                }
                else {
                    str[i] = str[j] = '1';
                    b -= 2;
                }
            }
        }

        // check for middle character
        if(len & 1) { // if length is odd
            if(str[hl] == '?')
                str[hl] = a ? '0' : '1';

            str[hl] == '0' ? --a : --b;
        }

        if(a != 0 || b != 0)
            cout << -1 << '\n';
        else
            cout << str << '\n';
    }

    return 0;
}
