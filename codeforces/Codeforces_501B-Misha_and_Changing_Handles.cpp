/**
* Codeforces Round #285 (Div. 2)
* Problem B - Misha and Changing Handles
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    map <string, string> parent, res;
    map <string, string>::iterator it;
    set <string> names;
    pair <set <string>::iterator, bool> check;
    string old, nw;
    int n;

    cin >> n;

    while(n--) {
        cin >> old >> nw;

        check = names.insert(nw);
        if(!check.second) continue; // request rejected

        it = parent.find(old);

        if(it == parent.end()) {
            parent[nw] = old;
            res[old] = nw;
            names.insert(old);
        }
        else {
            parent[nw] = it->second;
            res[it->second] = nw;
            parent.erase(it);
        }

        names.insert(nw);
    }

    cout << res.size() << '\n';
    for(it = res.begin(); it != res.end(); ++it)
        cout << it->first << ' ' << it->second << '\n';

    return 0;
}
