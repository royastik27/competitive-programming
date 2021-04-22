/**
* Codeforces Round #367 (Div. 2)
* Problem B - Interesting Drink
* Time: 311 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int nShops, nDays, amount;
    vector <int> price;
    vector <int>::iterator it;

    cin >> nShops;

    while(nShops--)
    {
        cin >> amount;
        price.push_back(amount);
    }

    sort(price.begin(), price.end());

    cin >> nDays;

    while(nDays--)
    {
        cin >> amount;

        it = upper_bound(price.begin(), price.end(), amount);

        cout << distance(price.begin(), it) << '\n';
    }

    return 0;
}
