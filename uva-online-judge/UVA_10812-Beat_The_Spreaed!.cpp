/**
* UVa 10812 - Beat the Spread!
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    int TC, sum, diff, x, y;

    cin >> TC;

    while(TC--)
    {
        cin >> sum >> diff;

        x = (sum + diff) / 2;
        y = x - diff;

        if(y < 0 || x + y != sum) cout << "impossible\n";
        else cout << x << ' ' << y << '\n';
    }

    return 0;
}
