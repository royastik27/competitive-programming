/**
 * Codeforces Round #702 (Div. 3)
 * Problem D - Permutation Transformation
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

#define LIM 101

using namespace std;

int ara[LIM], dep[LIM], n;
bool vis[LIM];

void solve(int b, int e, int level)
{
    int mx = 0, mx_pos, i;

    for(i = b; i <= e; ++i) {
        if(!vis[i] && ara[i] > mx) mx = ara[i], mx_pos = i;
    }

    if(mx) {
        vis[mx_pos] = true;
        dep[mx_pos] = level;
        solve(b, mx_pos-1, level+1);
        solve(mx_pos+1, e, level+1);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC;
    register int i;

    cin >> TC;

    while(TC--) {
        
        cin >> n;

        for(i = 0; i < n; ++i) cin >> ara[i];
        memset(vis, 0, (n+1)*sizeof(bool));

        --n;

        solve(0, n, 0);

        for(i = 0; i <= n; ++i) cout << dep[i] << ' ';
        cout << '\n';
    }

    return 0;
}
