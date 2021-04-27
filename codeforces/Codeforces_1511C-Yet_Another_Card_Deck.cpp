/**
* Educational Codeforces Round 107 (Rated for Div. 2)
* Problem C - Yet Another Card Deck
* Time: 1356 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <list>

using namespace std;

int main()
{
    int nCards, nQueries, color;
    list <int> ls;
    list <int>::iterator it;
    register int i;

    cin >> nCards >> nQueries;

    while(nCards--)
    {
        cin >> color;
        ls.push_back(color);
    }

    while(nQueries--)
    {
        cin >> color;

        it = ls.begin();

        for(i = 1, it = ls.begin(); *it != color; ++i, ++it);

        ls.erase(it);
        ls.push_front(color);
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
