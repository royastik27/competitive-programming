/**
 * Codeforces Round #274 (Div. 2)
 * Problem C - Exams
 * Time: 31ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    vector <pair <int, int> > date;

    int n, a, b, res, mn, mx;
    register int i;

    cin >> n;

    for(i = 0; i < n; ++i) {
        cin >> a >> b;
        date.push_back(make_pair(a, b));
    }

    sort(date.begin(), date.end());

    res = 0;
    for(i = 0; i < n; ++i) {
        if(date[i].first < date[i].second) mn = date[i].first, mx = date[i].second;
        else mn = date[i].second, mx = date[i].first;

        if(mn >= res) res = mn;
        else res = mx;
    }

    cout << res << '\n';

    return 0;
}
