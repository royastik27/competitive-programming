/**
* Codeforces Contest 977
* Codeforces Round #479 (Div. 3)
* Problem A - Wrong Subtraction
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    int n, k, rem;

    cin >> n >> k;

    while(k--)
    {
        rem = n % 10;

        if(rem == 0)
            n /= 10;
        else
            --n;
    }

    cout << n << '\n';

    return 0;
}
