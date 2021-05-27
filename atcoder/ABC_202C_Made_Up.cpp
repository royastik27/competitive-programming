/**
* AtCoder Beginner Contest 202
* Problem C - Made Up
* Time: 78 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 100001

int main()
{
    int n, Map[LIM], b[LIM], el;
    long long int res = 0;
    register int i;

    memset(Map, 0, sizeof(Map));

    cin >> n;

    // first sequence
    for(i = 0; i < n; ++i) {
        cin >> el;
        ++Map[el];
    }

    // second sequence
    for(i = 1; i <= n; ++i)
        cin >> b[i];

    // third sequence
    for(i = 0; i < n; ++i) {
        cin >> el;

        res += Map[b[el]];
    }

    cout << res << '\n';

    return 0;
}
