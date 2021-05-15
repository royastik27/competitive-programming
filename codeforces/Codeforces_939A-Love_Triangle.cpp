/**
* Codeforces Round #464 (Div. 2)
* Problem A - Love Triangle
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 5001

int main()
{
    ios_base::sync_with_stdio(0);

    int nPlanes, ara[LIMIT], a, b, c;
    register int i;

    cin >> nPlanes;

    for(i = 1; i <= nPlanes; ++i)
        cin >> ara[i];

    for(i = 1; i <= nPlanes; ++i)
    {
        a = ara[i];
        b = ara[a];
        c = ara[b];

        if(a != b && b != c && c != a && c == i) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
