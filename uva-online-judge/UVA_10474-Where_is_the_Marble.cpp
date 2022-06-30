/**
 * UVa 10474 - Where is the Marble?
 * Time: 40 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 10001

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC = 0, nMarbles, nQueries, m[LIM], num, prev_pos, cnt;
    register int i;

    while(1) {
        cin >> nMarbles >> nQueries;

        if(!nMarbles && !nQueries) break;

        memset(m, 0, sizeof(m));

        while(nMarbles--) {
            cin >> num;
            ++m[num];
        }

        prev_pos = 1; // for 1 based position
        num = 0;
        for(i = 1; i < LIM; ++i) {
            if(m[i]) {
                cnt = m[i];
                m[i] = prev_pos + num;
                prev_pos = m[i];
                num = cnt;
            }
        }

        cout << "CASE# " << ++TC << ":\n";
        while(nQueries--) {
            cin >> num;

            cout << num << ' ';
            if(m[num])
                cout << "found at " << m[num] << '\n';
            else cout << "not found\n";
        }
    }

    return 0;
}
