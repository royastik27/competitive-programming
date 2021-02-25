/**
* Codeforces Contest 978
* Codeforces Round #481 (Div. 3)
* Problem A - Remove Duplicates
* Time: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 1000

int Map[LIMIT + 1];

int main()
{
    int nElements, ara[LIMIT], Stack[LIMIT], Count, i, j;

    cin >> nElements;

    for(i = 0; i < nElements; ++i)
    {
        cin >> ara[i];
    }

    Count = 0;
    for(i = nElements - 1, j = 0; i >= 0; --i)
    {
        if(Map[ara[i]] == 0)
        {
            ++Count;
            Stack[j++] = ara[i];
        }

        ++Map[ara[i]];
    }

    //printing
    cout << Count << '\n';
    for(i = j-1; i >= 0; --i)
    {
        cout << Stack[i];

        if(i) cout << ' ';
    }
    cout << '\n';


    return 0;
}
