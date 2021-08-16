/**
 * Codeforces Round #277.5 (Div. 2)
 * Problem C - Given Length and Sum of Digits...
 * Time: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define LIM 101

int main()
{
    ios_base::sync_with_stdio(0);

    int len, sod, quo, i;
    char mx[LIM], mn[LIM];

    cin >> len >> sod;

    if(!sod) {
        if(len == 1) cout << "0 0\n";
        else cout << "-1 -1\n";
    }
    else if(ceil(sod/9.0) > len) cout << "-1 -1\n";
    else {
        quo = sod / 9;

        i = 0;
        while(quo--) {
            mx[i] = mn[i] = '9';
            ++i;
        }

        if(sod % 9) {
            mx[i] = mn[i] = sod % 9 + '0';
            ++i;
        }

        // maximum number
        quo = i; // for temporary use only
        while(i < len) mx[i++] = '0';
        
        // minimum number
        i = quo; // getting back the value
        if(i < len) {
            if(mn[i-1] == '1') --i;
            else --mn[i-1];
            while(i < len-1) mn[i++] = '0';
            mn[i++] = '1';
        }
        reverse(mn, mn+i);

        mx[len] = mn[len] = '\0';

        cout << mn << ' ' << mx << '\n';
    }

    return 0;
}
