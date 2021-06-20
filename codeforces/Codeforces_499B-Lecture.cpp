/**
* Codeforces Round #284 (Div. 2)
* Problem B - Lecture
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    string s1, s2;
    map <string, string> mp;

    cin >> n >> m;

    while(m--) {
        cin >> s1 >> s2;

        mp[s1] = (s2.size() < s1.size()) ? s2 : s1;
    }

    while(n--) {
        cin >> s1;

        cout << mp[s1] << ' ';
    }
    cout << '\n';

    return 0;
}
