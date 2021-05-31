/**
* Codeforces Round #320 (Div. 2) [Bayan Thanks-Round]
* Problem A - Raising Bacteria
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    int pow2[31], x, cnt = 0;
    register int i;

    pow2[0] = 1;
    for(i = 1; i <= 30; ++i)
        pow2[i] = pow2[i-1] * 2;

    cin >> x;

    for(i = 30; x; --i) {
        if(x >= pow2[i]) {
            ++cnt;
            x -= pow2[i];
        }
    }

    cout << cnt << '\n';

    return 0;
}
