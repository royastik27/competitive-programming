/**
* SPOJ CEQU - Crucial Equation
* Time: 1.55s
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;

    return gcd(b, a%b);
}

int main()
{
    int k = 0, TC, a, b, c;

    cin >> TC;

    while(TC--)
    {
        cin >> a >> b >> c;

        cout << "Case " << ++k << ": ";

        if(c % gcd(a, b))
            cout << "No\n";
        else cout << "Yes\n";
    }

    return 0;
}
