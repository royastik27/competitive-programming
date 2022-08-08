/**
 * Cefalo CodeFiesta 2022: AUST IUPC
 * Problem E - Min Cost Sort
 * Time: 
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

#define LIM 301
#define INF 600

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC, n, a[LIM], sortedA[LIM], i, j, rep, pos, match, cost, mnCost, total;
    sortedA[0] = 0;

    cin >> TC;

    while(TC--)
    {
        cin >> n;

        for(i = 1; i <= n; ++i)
        {
            cin >> a[i];
            sortedA[i] = a[i];
        }

        sort(sortedA, sortedA+n+1);
        total = 0;

        for(rep = 1; rep <= n; ++rep)
        {
            mnCost = INF;

            for(pos = 1; pos <= n; ++pos)
            {
                if(a[pos] != sortedA[pos])
                {
                    for(match = 1; match <= n; ++match)
                    {
                        if(match == pos) continue;

                        if(a[match] == sortedA[pos])
                        {
                            cost = pos + match;
                            break;
                        }
                    }

                    if(cost < mnCost)
                    {
                        mnCost = cost;
                        i = pos; j = match;
                    }
                }
            }

            if(mnCost != INF)
            {
                total += mnCost;
                swap(a[i], a[j]);
            }
        }

        cout << total << '\n';
    }
    
    return 0;
}
