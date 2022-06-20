/**
* Educational Codeforces Round 130 (Rated for Div. 2)
* Problem B - Promo
* Time: 265 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

#define LIM 200000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, nQueries, x, y, price[LIM], i;
    long long int pre[LIM + 1];

    cin >> n >> nQueries;

    for(i = 0; i < n; ++i) cin >> price[i];

    sort(price, price+n, greater<int>());

    pre[0] = 0;
    for(i = 0; i < n; ++i)
        pre[i+1] = pre[i] + price[i];

    while(nQueries--)
    {
        cin >> x >> y;

        cout << pre[x] - pre[x - y] << '\n';
    }

    return 0;
}
