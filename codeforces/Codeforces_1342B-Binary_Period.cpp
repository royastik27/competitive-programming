/**
 * Educational Codeforces Round 86 (Rated for Div. 2)
 * Problem B - Binary Period
 * Time: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, c0, c1;
    char str[101], ch;
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> str;

        c0 = c1 = 0;
        for(i = 0; str[i] != 0; ++i) {
            if(str[i] == '0') ++c0;
            else ++c1;
        }

        if(!c0 || !c1) cout << str << '\n';
        else {
            ch = str[0];
            cout << ch;   

            for(i = 1; str[i] != '\0';) {
                if(ch == str[i]) {
                    if(ch == '0') cout << 1;
                    else cout << 0;
                }
                else {
                    cout << str[i];
                    ++i;
                }

                ch = (ch == '0') ? '1' : '0';
            }
            cout << '\n';
        }
    }

    return 0;
}
