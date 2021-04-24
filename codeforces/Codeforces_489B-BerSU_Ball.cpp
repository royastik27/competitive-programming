/**
* Codeforces Round #277.5 (Div. 2)
* Problem B - BerSU Ball
* Dynamic Programming Solution
* Time: 31 ms
* AUTHOR: Astik Roy
**/
 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
 
using namespace std;
 
#define LIMIT 100
int dp[LIMIT][LIMIT], nBoys, nGirls, boy[LIMIT], girl[LIMIT];
 
int max_pair(int i = 0, int j = 0)
{
    if(i == nBoys || j == nGirls)
        return 0;
 
    else if(dp[i][j] != -1)
        return dp[i][j];
 
    else if(abs(boy[i]-girl[j]) <= 1)
        return dp[i][j] = 1 + max_pair(i+1, j+1);
 
    else if(boy[i] < girl[j])
        return dp[i][j] = max_pair(i+1, j);
 
    else
        return dp[i][j] = max_pair(i, j+1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    memset(dp, -1, sizeof(dp));
 
    register int i;
 
    cin >> nBoys;
    for(i = 0; i < nBoys; ++i)
        cin >> boy[i];
 
    cin >> nGirls;
    for(i = 0; i < nGirls; ++i)
        cin >> girl[i];
 
    sort(boy, boy+nBoys);
    sort(girl, girl+nGirls);
 
    cout << max_pair() << '\n';
 
    return 0;
}
