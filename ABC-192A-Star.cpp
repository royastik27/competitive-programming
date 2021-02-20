/**
* Atcoder Beginner Contest 192
* Problem A - Star
* Time: 8 ms
* Author: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int coins, nextPrize;

    cin >> coins;

    cout << (floor(coins / 100.0) + 1) * 100 - coins << '\n';

    return 0;
}
