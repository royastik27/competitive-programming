/**
* Codeforces Round #277.5 (Div. 2)
* Problem B - BerSU Ball
* Iterative Solution using two pointer method
* Time: 31 ms
* AUTHOR: Astik Roy
**/
 
#include <iostream>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
#define LIMIT 100
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    int nBoys, nGirls, boy[LIMIT], girl[LIMIT], res;
    register int i, j;
 
    cin >> nBoys;
    for(i = 0; i < nBoys; ++i)
        cin >> boy[i];
 
    cin >> nGirls;
    for(i = 0; i < nGirls; ++i)
        cin >> girl[i];
 
    sort(boy, boy+nBoys);
    sort(girl, girl+nGirls);
 
    i = j = res = 0;
    while(i < nBoys && j < nGirls)
    {
        if(abs(boy[i]-girl[j]) <= 1)
        {
            ++res;
            ++i;
            ++j;
        }
        else if(boy[i] < girl[j])
            ++i;
        else
            ++j;
    }
 
    cout << res << '\n';
 
    return 0;
}
