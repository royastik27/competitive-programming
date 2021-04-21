/**
* Codeforces Beta Round #1
* Problem A - Theatre Square
* Time: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m, a;
    long long res;

    cin >> n >> m >> a;

    res = ceil((double)n/a) * ceil((double)m/a);

    cout << res << '\n';

    return 0;
}
