/**
* Codeforces Round #653 (Div. 3)
* Problem C - Move Brackets
* Time: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, opening, closing;
    char str[51];
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> n >> str;

        opening = closing = 0;

        for(i = 0; i < n; ++i) {
            if(str[i] == '(')
                ++ opening;
            else if(opening)
                --opening;
        }

        cout << opening << '\n';
    }

    return 0;
}
