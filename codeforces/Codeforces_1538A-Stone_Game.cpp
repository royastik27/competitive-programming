/**
* Codeforces Round #725 (Div. 3)
* Problem A - Stone Game
* Time: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>
 
using namespace std;
 
#define LIM 100
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    int  TC, n, el, mn, mx, mnpos, mxpos;
    register int i;
 
    cin >> TC;
 
    while(TC--) {
        cin >> n;
 
        mn = LIM + 1;
        mx = -1;
        for(i = 0; i < n; ++i) {
            cin >> el;
 
            if(el > mx) {
                mx = el;
                mxpos = i;
            }
 
            if(el < mn) {
                mn = el;
                mnpos = i;
            }
        }
 
        cout << min(n - abs(mxpos-mnpos) + 1, min(max(mnpos, mxpos) + 1, n - min(mnpos, mxpos))) << '\n';
    }
 
    return 0;
}
