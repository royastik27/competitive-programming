/**
* Educational Codeforces Round 85 (Rated for Div. 2)
* Problem B - Middle Class
* Time: 93 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

#define LIMIT 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, nPeople, min_money, savings[LIMIT], res;
    long long int rem;
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> nPeople >> min_money;

        for(i = 0; i < nPeople; ++i)
            cin >> savings[i];

        sort(savings, savings+nPeople, greater<int>());

        rem = res = 0;

        for(i = 0; i < nPeople; ++i)
        {
            if(savings[i] >= min_money)
            {
                rem += savings[i] - min_money;
                ++res;
            }
            else
            {
                if(min_money - savings[i] <= rem)
                {
                    ++res;
                    rem -= min_money - savings[i];
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}
