/**
* UVa 162 - Beggar My Neighbour
* Time: 10 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

deque <int> player[2];
vector <int> st;
bool activePlayer, isWon;

int get_code(char card[])
{
    switch(card[1])
    {
    case 'T':
        return 10;
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    case 'A':
        return 14;
    default:
        return (int)(card[1] - '0');
    }
}

void play(int limit)
{
    activePlayer ^= 1; // changing the active player

    int i, top;

    for(i = 0; i < limit; ++i)
    {

        if(!player[activePlayer].size())
        {
            isWon = true;
            return;
        }

        top = player[activePlayer].back();
        player[activePlayer].pop_back();
        st.push_back(top);

        if(top > 10)    // face card
        {
            play(top - 10);
            return;
        }
    }

    for(i = 0; i < st.size(); ++i)
        player[activePlayer ^ 1].push_front(st[i]);

    st.clear();

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    char card[3];
    int top, i;

    while(cin >> card && card[0] != '#')
    {

        player[1].push_back(get_code(card));

        for(i = 1; i < 52; ++i)
        {
            cin >> card;

            if(i & 1) player[0].push_back(get_code(card));
            else player[1].push_back(get_code(card));
        }

        // start playing
        // 0 - player 1 - dealer
        // 1 - player 2 - nondealer
        activePlayer = 1;
        isWon = false;

        while(!player[activePlayer].empty())
        {

            top = player[activePlayer].back();
            player[activePlayer].pop_back();
            st.push_back(top);

            if(top > 10)
            {
                // for face card
                play(top - 10);

                if(isWon) break; // opponent won ( change active player )
            }

            activePlayer ^= 1; // changing active player
        }

        if(activePlayer == 0)
            cout << 2 << setw(3) << player[1].size() << '\n';
        else
            cout << 1 << setw(3) << player[0].size() << '\n';

        // releasing memory
        st.clear();
        while(!player[0].empty())
            player[0].pop_back();
        while(!player[1].empty())
            player[1].pop_back();
    }

    return 0;
}
