/**
* Good Bye 2014
* Problem A - New Year Transportation
* Time: 46 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

#define LIMIT 30000

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int nCells, dest, portal[LIMIT], i;
    bool isPossible = true;

    cin >> nCells >> dest;

    for(i = 1; i < nCells; ++i)
        cin >> portal[i];

    i = 1;
    while(i < nCells)
    {
        if(i == dest)
            break;
        else if(i > dest)
        {
            isPossible = false;
            break;
        }

        i += portal[i];
    }

    if(isPossible && i == dest)
        cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
