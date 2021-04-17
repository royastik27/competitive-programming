/**
* Codeforces Round #560 (Div. 3)
* Problem B - Polycarp Training
* Time: 390 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <set>

using namespace std;

int main()
{
    multiset <int> s;
    multiset <int>::iterator it;
    int nContests, nProblems, nDays;

    cin >> nContests;

    while(nContests--)
    {
        cin >> nProblems;
        s.insert(nProblems);
    }

    nDays = 1;
    for(it = s.begin(); it != s.end(); ++it)
        if(*it >= nDays) ++nDays;

    cout << --nDays << '\n';

    return 0;
}
