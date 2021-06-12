/**
* Codeforces Round #377 (Div. 2)
* Problem A - Buy a Shovel
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int k, r, i, pay;

    cin >> k >> r;

    i = 0;
    while(1) {

        pay = 10 * i;

        if(pay && pay % k == 0) {
            cout << pay / k << '\n';
            break;
        }

        pay += r;

        if(pay % k == 0) {
            cout << pay / k << '\n';
            break;
        }

        ++i;
    }

    return 0;
}
