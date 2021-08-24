/**
 * Codeforces Beta Round #25 (Div. 2 Only)
 * Problem A - IQ test
 * Time: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, odd, even, oddpos, evenpos, el;
    register int i;

    cin >> n;

    odd = even = 0;

    for(i = 1; i <= n; ++i) {
        cin >> el;

        if(el & 1) {
            ++odd;
            oddpos = i;
        } else {
            ++even;
            evenpos = i;
        }
    }

    if(even == 1) cout << evenpos << '\n';
    else cout << oddpos << '\n';

    return 0;
}
