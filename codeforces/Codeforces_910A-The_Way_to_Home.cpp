/**
* Testing Round #14 (Unrated)
* Problem A - The Way to Home
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    char axis[101];
    int n, dis, curr, i, next_move, jump = 0;

    cin >> n >> dis >> axis;

    curr = 0;
    while(curr < n-1)
    {
        next_move = 0;
        for(i = curr+1; i < n && i <= dis+curr; ++i)
            if(axis[i] == '1')
                next_move = i;

        if(!next_move)
        {
            cout << -1 << '\n';
            return 0;
        }

        curr = next_move;
        ++jump;
    }

    cout << jump << '\n';

    return 0;
}
