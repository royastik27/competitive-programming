/**
* Codeforces Round #486 (Div. 3)
* Problem B - Substrings Sort
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return (a.size() < b.size());
}

bool isSubstr(string main, string subStr)
{
    int i, j, k, subStr_sz = subStr.size(), diff;

    diff = main.size() - subStr_sz;

    for(i = 0; i <= diff;  ++i) {
        for(j = i, k = 0; j < i + subStr_sz; ++j) {
            if(main[j] == subStr[k])
                ++k;
        }

        if(k == subStr_sz)
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    string str;
    vector <string> strs;
    register int i;

    cin >> n;

    for(i = 0; i < n; ++i) {
        cin >> str;
        strs.push_back(str);
    }

    sort(strs.begin(), strs.end(), cmp);

    for(i = 1; i < n; ++i) {
        if(!isSubstr(strs[i], strs[i-1])) {
           cout << "NO\n";
           return 0;
        }
    }

    cout << "YES\n";
    for(i = 0; i < n; ++i)
        cout << strs[i] << '\n';

    return 0;
}
