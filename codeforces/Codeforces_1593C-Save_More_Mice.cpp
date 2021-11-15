/**
 * Codeforces Round #748 (Div. 3)
 * Problem C - Save More Mice
 * Time: 140 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

#define LIM 400000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, k, pos[LIM], res;
    long long int cat;
    register int i;

    cin >> TC;

    while(TC--) {
        cin >> n >> k;

        for(i = 0; i < k; ++i) cin >> pos[i];

        sort(pos, pos+k);

        cat = res = 0;
        for(i = k-1; i >= 0; --i) {
            if(cat < pos[i]) ++res;

            cat += n - pos[i];
        }

        cout << res << '\n';
    }

    return 0;
}
