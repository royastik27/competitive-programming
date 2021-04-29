/**
* Codeforces Round #629 (Div. 3)
* Problem C - Ternary XOR
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 50001

int main()
{
    ios_base::sync_with_stdio(0);

    int TC, len;
    char x[LIMIT], a[LIMIT], b[LIMIT];
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> len >> x;

        // for the sake of easy solution
        x[len] = '1';
        x[len+1] = '\0';

        for(i = 0; x[i] != '1'; ++i)
        {
            if(x[i] == '2')
                a[i] = b[i] = '1';
            else
                a[i] = b[i] = '0';
        }

        a[i] = '1'; b[i] = '0';

        for(i = i+1; i < len; ++i)
        {
            a[i] = '0';
            b[i] = x[i];
        }

        a[len] = b[len] = '\0';

        cout << a << '\n' << b << '\n';
    }

    return 0;
}
