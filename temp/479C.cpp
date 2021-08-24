/**
 * https://codeforces.com/problemset/problem/479/C
 * Problem
 * Time:
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, a, b, res;
    map <int, pair<int, int> > m;
    map <int, pair<int, int> >::iterator it, it2;

    cin >> n;

    while(n--) {
        cin >> a >> b;

        if(m.find(a) == m.end()) // new element
            m[a].first = m[a].second = b;
        else {
            if(m[a].first > b) m[a].first = b; // for minimum value
            else if(m[a].second < b) m[a].second = b; // for maximum value
        }
    }

    res = (--m.end())->second.second;

    for(it = ++m.begin(), it2 = m.begin(); it != m.end(); ++it, ++it2) {
        if(it->second.first < it2->second.first || it->second.second < it2->second.second) {
            res = (--m.end())->first;
            break;
        }
    }

    cout << res << '\n';

    return 0;
}
