/**
 * Codeforces Round #736 (Div. 2)
 * Problem C - Web of Lies
 * Time: 452 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 200001

void ready(int * a, int * b)
{
    if(*a > *b) {   // swap
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int nNobles, nFriendships, op, nQueries, conn[LIM], vul[LIM], a, b, res;

    // initializing
    memset(conn, 0, sizeof(conn));
    memset(vul, 0, sizeof(vul));

    cin >> nNobles >> nFriendships;

    res = nNobles;
    while(nFriendships--) {
        cin >> a >> b;

        ready(&a, &b);

        ++conn[a];
        if(!vul[a]) --res;
        vul[a] = true;
    }

    cin >> nQueries;

    while(nQueries--) {
        cin >> op;

        if(op == 3) {
            cout << res << '\n';
            continue;
        }

        cin >> a >> b;
        ready(&a, &b);

        if(op == 1) {   // add friendship
            ++conn[a];
            if(!vul[a]) --res;
            vul[a] = true;
        }
        else if(--conn[a] == 0) {   // remove friendship
            ++res;
            vul[a] = false;
        }
    }

    return 0;
}
