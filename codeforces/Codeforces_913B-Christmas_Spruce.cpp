/**
* Hello 2018
* Problem B - Christmas Spruce
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

#define LIM 1001

int main()
{
    ios_base::sync_with_stdio(0);

    int nVertices, par, res, Count;
    vector <int> con[LIM];
    register int i, j;

    cin >> nVertices;

    for(i = 2; i <= nVertices; ++i) {
        cin >> par;
        con[par].push_back(i);
    }

    res = 0;
    for(i = 1; i <= nVertices; ++i) {

        if(!con[i].size())
            continue;

        Count = 0;
        for(j = 0; j < con[i].size(); ++j) {
            if(con[con[i][j]].size() == 0)
                ++Count;
        }

        if(Count < 3) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}
