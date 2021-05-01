/**
* Codeforces Round #165 (Div. 2)
* Problem A - Fancy Fence
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    int TC, x;

    cin >> TC;

    while(TC--)
    {
        cin >> x;

        if(360 % (180-x) == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
