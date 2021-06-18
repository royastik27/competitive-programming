/**
* LightOJ 1047 - Neighbor
* Time: 871 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2

int n, cost[20][3];

int solve(int house = 0, int parentColor = -1)
{
    if(house == n) return 0;

    switch(parentColor)
    {
    case RED:
        return min(cost[house][GREEN] + solve(house+1, GREEN), cost[house][BLUE] + solve(house+1, BLUE));
    case GREEN:
        return min(cost[house][RED] + solve(house+1, RED), cost[house][BLUE] + solve(house+1, BLUE));
    case BLUE:
        return min(cost[house][RED] + solve(house+1, RED), cost[house][GREEN] + solve(house+1, GREEN));
    default: // for choosing the cost of first house
        return min(cost[house][RED] + solve(house+1, RED), min(cost[house][GREEN] + solve(house+1, GREEN), cost[house][BLUE] + solve(house+1, BLUE)));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int k = 0, TC;
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

        cout << "Case " << ++k << ": " << solve() << '\n';
    }

    return 0;
}
