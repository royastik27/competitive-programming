/**
* Codeforces Round #271 (Div. 2)
* Problem B - Worms
* Time: 311 ms
* AUTHOR: Astik Roy
**/
 
#include <iostream>
 
using namespace std;
 
#define LIMIT 100001
 
int ara[LIMIT], n;
 
int lower_bound(int value)
{
    int low = 1, high = n, mid;
 
    while(low <= high)
    {
        mid = (low + high) / 2;
 
        if(value > ara[mid])
            low = mid+1;
        else
            high = mid-1;
    }
 
    return low;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    int nQueries, query;
    register int i;
 
    cin >> n;
 
    cin >> ara[1];
    for(i = 2; i <= n; ++i)
    {
        cin >> ara[i];
        ara[i] += ara[i-1];
    }
 
    cin >> nQueries;
 
    while(nQueries--)
    {
        cin >> query;
 
        cout << lower_bound(query) << '\n';
    }
 
    return 0;
}
