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

    int n, a, b, res;
    register int i;

    cin >> n;

    for(i = 0; i < n; ++i) {
        cin >> a >> b;
        date.push_back(make_pair(a, b));
    }

    sort(date.begin(), date.end());

    res = 0;
    for(i = 0; i < n; ++i)
        res = (date[i].second >= res) ? date[i].second : date[i].first;

    cout << res << '\n';

    return 0;
}
