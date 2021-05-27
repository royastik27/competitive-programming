/**
* AtCoder Beginner Contest 202
* Problem A - Three Dice
* Time: 14 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    cout << abs(6 - a) + abs(6 - b) + abs(6 - c) + 3 << '\n';

    return 0;
}
