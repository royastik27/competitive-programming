/**
* Codeforces Contest 977
* Codeforces Round #479 (Div. 3)
* Problem C - Less or Equal
* Time: 421 ms
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int nElements, k;

    cin >> nElements >> k;

    // array is 1 based indexed
    int ara[nElements + 1];

    for(int i = 1; i <= nElements; ++i)
        cin >> ara[i];

    sort(ara + 1, ara + nElements + 1);

    if(k == 0)
    {
        if(ara[1] == 1)
            cout << -1;
        else
            cout << ara[1] - 1;
    }
    else if(k == nElements)
        cout << ara[k];
    else if(ara[k] == ara[k+1])
        cout << -1;
    else
        cout << ara[k];

    cout << '\n';

    return 0;
}
