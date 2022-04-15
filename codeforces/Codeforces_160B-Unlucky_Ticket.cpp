/**
* Codeforces Round #111 (Div. 2)
* Problem B - Unlucky Ticket
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

#define LIM 100

int main()
{
    int n, firstHalf[LIM], secondHalf[LIM], i, j;
    char ch;

    cin >> n;

    j = -1;
    for(i = 0; i < n; ++i)
    {
        cin >> ch;

        firstHalf[++j] = ch - '0';
    }

    j = -1;
    for(; i < n*2; ++i)
    {
        cin >> ch;
        secondHalf[++j] = ch - '0';
    }

    sort(firstHalf, firstHalf+n);
    sort(secondHalf, secondHalf+n);

    bool isPossible = true;

    for(i = 0; i < n; ++i)
    {
        if(firstHalf[i] >= secondHalf[i])
            isPossible = false;
    }

    // Reinitializing the boolean
    if(isPossible) {
        cout << "YES\n";
        return 0;
    } else isPossible = true;

    for(i = 0; i < n; ++i)
    {
        if(firstHalf[i] <= secondHalf[i])
            isPossible = false;
    }

    if(isPossible)
        cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
