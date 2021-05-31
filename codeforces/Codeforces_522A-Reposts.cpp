/**
* VK Cup 2015 - Qualification Round 1
* Problem A - Reposts
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map <string, vector <string> > m;

int solve(string a)
{
    int sz = m[a].size(), mx = 1;

    for(int i = 0; i < sz; ++i) {
        mx = max(mx, 1 + solve(m[a][i]));
    }

    return mx;
}

string tolwr(string a)
{
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] < 'a')
            a[i] += 32;
    }

    return a;
}

int main()
{
    string x, y;
    register int i;

    int nReposts;

    cin >> nReposts;

    while(nReposts--)
    {
        cin >> x >> y >> y;

        x = tolwr(x);
        y = tolwr(y);

        m[y].push_back(x);
    }

    cout << solve("polycarp") << '\n';

    return 0;
}
