/**
 * https://codeforces.com/contest/479/problem/C
 * Problem
 * Time:
 * AUTHOR: Astik Roy
 * Implement using map
**/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(NULL);

    int n, a, b, res = 0, mn;
    vector <pair<int, int> > date;
    register int i;

    cin >> n;

    for(i = 0; i < n; ++i)
        cin >> a >> b;
        date.push_back(make_pair(a, b));
    }

    sort(date.begin(), date.end());

    for(i = 0; i < n; ++i) {
        mn = min(date[i].first, date[i].second);
        if(mn >= res) res = mn;
        else res = max(date[i].first, date[i].second);
    }

    cout << res << '\n';

    return 0;
}
