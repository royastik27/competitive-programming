/**
* Codeforces Round #267 (Div. 2)
* Problem B - Fedor and New Game
* Time: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int nTypes, nPlayers, k, army[1001], diff, friends;
    bitset <20> fedor, player;
    register int i, j;

    cin >> nTypes >> nPlayers >> k;

    ++nPlayers;
    for(i = 0; i < nPlayers; ++i)
        cin >> army[i];

    for(i = 0; army[nPlayers-1] && i < nTypes; ++i)
    {
        fedor[i] = army[nPlayers-1] % 2;
        army[nPlayers-1] >>= 1;
    }

    // comparing with others;
    friends = 0;
    for(i = nPlayers-2; i >= 0; --i)
    {
        player.reset();

        for(j = 0; army[i] && j < nTypes; ++j)
        {
            player[j] = army[i] % 2;
            army[i] >>= 1;
        }

        diff = 0;
        for(j = 0; j < nTypes; ++j)
        {
            if(fedor[j] != player[j])
                ++diff;
        }

        if(diff <= k) ++ friends;
    }

    cout << friends << '\n';

    return 0;
}
