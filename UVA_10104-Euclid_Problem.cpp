/**
* UVA 10104 - Euclid Problem
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

int egcd(int a, int b, int *x, int *y)
{
    if(b == 0)
    {
        *x = 1; *y = 0;
        return a;
    }

    int x1, y1;
    int d = egcd(b, a%b, &x1, &y1);

    *y = x1 - (a/b)*y1;
    *x = y1;

    return d;
}

int main()
{
    int a, b, gcd, x, y;

    while(cin >> a >> b)
    {
        gcd = egcd(a, b, &x, &y);

        cout << x << ' ' << y << ' ' << gcd << endl;
    }

    return 0;
}
