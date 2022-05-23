/**
 * Educational Codeforces Round 2
 * Problem B - Queries about less or equal elements
 * Time: 186 ms
 * AUTHOR: Astik Roy
 **/

#include <iostream>
#include <algorithm>

using namespace std;

#define LIM 200000

int upperBound(int a[], int e, int val)
{
    int b = 0, mid;
    --e;

    while (b <= e)
    {
        mid = (b + e) / 2;

        if (a[mid] > val)
            e = mid - 1;
        else // for less and equal
            b = mid + 1;
    }

    return b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, a[LIM], el;

    cin >> n >> m;

    for (i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);

    for (i = 0; i < m; ++i)
    {
        cin >> el;

        cout << upperBound(a, n, el) << ' ';
    }
    cout << '\n';

    return 0;
}
