/**
* Codeforces Round #202 (Div. 2)
* Problem A - Cinema Line
* Time: 154 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int nPeople, amount, c25, c50;
    bool isPossible = true;

    cin >> nPeople;

    c25 = c50 = 0;
    while(nPeople--)
    {
        cin >> amount;

        switch(amount)
        {
        case 25:
            ++c25;
            break;
        case 50:
            ++c50;
            if(!c25) isPossible = false;
            --c25;
        break;
        case 100:
            if(c25 && c50) {
                --c25;
                --c50;
            }
            else if(c25 >= 3)
                c25 -= 3;
            else
                isPossible = false;
            break;
        }
    }

    if(isPossible) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
