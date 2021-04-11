/**
* Divide by Zero 2021 and Codeforces Round #714 (Div. 2)
* Problem A - Array and Peaks
* Time: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>
 
using namespace std;
 
int main()
{
    int TC, n, nPeaks, ara[101];
    register int i;
 
    cin >> TC;
 
    ara[1] = 1;
    while(TC--)
    {
        cin >> n >> nPeaks;
 
        if(nPeaks > ceil(n/2.0) - 1)
            cout << -1 << '\n';
        else
        {
            for(i = 2; i <= n; ++i)
            {
                if(nPeaks)
                {
                    ara[i+1] = i;
                    ara[i] = i + 1;
                    ++i;
                    --nPeaks;
                }
                else
                    ara[i] = i;
            }
 
            // printing
            for(i = 1; i <= n; ++i)
                cout << ara[i] << ' ';
            cout << '\n';
        }
    }
 
    return 0;
}
