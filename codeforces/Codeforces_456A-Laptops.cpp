/**
* Codeforces Round #260 (Div. 2)
* Problem A - Laptops
* Time: 343 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <set>

using namespace std;

#define LIMIT 100001

int main()
{
    int nLaptops, price, quality, Min;
    register int i;
    set <pair<int, int> > laptop;
    set <pair<int, int> >::iterator it;

    cin >> nLaptops;

    for(i = 0; i < nLaptops; ++i)
    {
        cin >> price >> quality;
        laptop.insert(make_pair(price, quality));
    }

    Min = LIMIT;
    it = laptop.end();
    --it;

    for(i = 0; i < nLaptops; ++i, --it)
    {
        if(it->second <= Min)
            Min = it->second;
        else
        {
            cout << "Happy Alex\n";
            return 0;
        }
    }

    cout << "Poor Alex\n";

    return 0;
}
