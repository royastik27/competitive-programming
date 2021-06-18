/**
* AtCoder Beginner Contest 172
* Problem C - Tsundoku
* Time: 51 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define LIM 200001
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    int n, m, k, i, cnt, res;
    long long a[LIM], b[LIM], * ptr;
 
    cin >> n >> m >> k;
 
    // prefix sum
    ++n;
    ++m;
 
    a[0] = 0;
    for(i = 1; i < n; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
    }
 
    b[0] = 0;
    for(i = 1; i < m; ++i) {
        cin >> b[i];
        b[i] += b[i-1];
    }
 
    res = -1;
    for(i = 0; i < n; ++i) {
        if(a[i] > k) break;
 
        ptr = upper_bound(b, b+m, k - a[i]);
 
        cnt = i + (ptr - b) - 1;
 
        if(cnt > res) res = cnt;
    }
 
    cout << res << '\n';
 
    return 0;
}
