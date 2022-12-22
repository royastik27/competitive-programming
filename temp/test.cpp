/**
 * Codeforces Round #809 (Div. 2)
 * Problem C - Qpwoeirut And The City
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

vector < pair <int, int> > item;
int capacity;

int knapsack()
{
    int n = item.size(), i, j;

    sort(item.begin(), item.end());

    vector < vector <int> > dp(n+1, vector <int> (capacity+1, 0));

    for(i = 1; i <= n; ++i)
    {
        for(j = item[i-1].first; j <= capacity; ++j)
            dp[i][j] = max(dp[i-1][j], item[i-1].second + dp[i-1][j - item[i-1].first]);
    }

    return dp[n][capacity];    
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    item.push_back({ 2, 3 });
    item.push_back({ 3, 5 });
    item.push_back({ 2, 4 });
    item.push_back({ 4, 3 });

    capacity = 5;
 
    cout << knapsack() << '\n';
 
    return 0;
}