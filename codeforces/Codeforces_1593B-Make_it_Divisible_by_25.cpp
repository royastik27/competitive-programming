/**
 * Codeforces Round #748 (Div. 3)
 * Problem B - Make it Divisible by 25
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 18

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, len, to_remove, res;
    register int i, j;
    char num[LIM + 1];

    cin >> TC;

    while(TC--) {
        cin >> num;

        len = strlen(num);
        --len;

        to_remove = res = LIM;

        for(i = len; i >= 0; --i) {
            if(num[i] == '0') {
                for(j = i - 1; j >= 0; --j) {
                    if(num[j] == '5' || num[j] == '0') {
                        to_remove = len - i + (i - j) - 1;
                        break;
                    }
                }
            }
            if(num[i] == '5') {
                for(j = i - 1; j >= 0; --j) {
                    if(num[j] == '2' || num[j] == '7') {
                        to_remove = len - i + (i - j) - 1;
                        break;
                    }
                }
            }

            if(to_remove < res) res = to_remove;
        }

        cout << res << '\n';
    }

    return 0;
}
