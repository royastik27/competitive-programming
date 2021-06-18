/**
* AtCoder Beginner Contest 100
* Problem B - Ringo's Favorite Numbers
* Time: 8 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int d, n, res;

    cin >> d >> n;

    if(n == 100) ++n;

    cout << n * (int)pow(100, d) << '\n';

    return 0;
}
