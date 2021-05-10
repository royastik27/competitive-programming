/**
* Codeforces Round #119 (Div. 2)
* Problem A - Cut Ribbon
* Unique Solution
* Time: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define INF -4001

int len, cut[3], mem[3][4001];

int solve(int i, int amount)
{
    if(amount == 0)
        return 0;
    else if(amount < 0 || i == 3)
        return INF;
    else if(mem[i][amount] != -1)
        return mem[i][amount];

    return mem[i][amount] = max(1 + solve(i, amount - cut[i]), solve(i+1, amount));
}

int main()
{
    memset(mem, -1, sizeof(mem));

    cin >> len >> cut[0] >> cut[1] >> cut[2];

    cout << solve(0, len) << '\n';

    return 0;
}
