/**
* Codeforces Round #639 (Div. 2)
* Problem B - Card Constructions
* Time: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LIMIT 1000000000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int base, TC, nCards, dist, res;
    vector <int> card;
    vector <int>::iterator it;

    // pre-calculating the numbers of cards
    card.push_back(0);
    base = 2;
    for(int i = 1; ; ++i)
    {
        card.push_back(card[i-1] + base + i-1);

        if(card[i] > LIMIT)
            break;

        base += 2;
    }

    cin >> TC;

    while(TC--)
    {
        cin >> nCards;

        it = upper_bound(card.begin(), card.end(), nCards);
        --it;

        res = 0;
        while(it != card.begin())
        {
            ++res;

            nCards -= *it;

            it = upper_bound(card.begin(), card.end(), nCards);
            --it;
        }

        cout << res << '\n';
    }

    return 0;
}
