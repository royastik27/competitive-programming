/**
* SPOJ TREEDEGREE - Degree of a Tree
* Unique Solution
* Time: 2.39 sec
* AUTHOR: Astik Roy
**/

#include <bits/stdc++.h>

using namespace std;

#define LIMIT 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, ara[2 * LIMIT], deg[LIMIT + 1], Max, temp;
    stack <int> parent;
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> n;

        deg[1] = 0;
        for(i = 2; i <= n; ++i)
            deg[i] = 1;

        // getting input
        n *= 2;
        for(i = 0; i < n; ++i)
            cin >> ara[i];

        // operation
        parent.push(1);
        deg[1] = 0;
        Max = -1;

        for(i = 1; i < n; ++i)
        {
            if(ara[i] == parent.top())
            {
                // updating max
                if(deg[parent.top()] > Max)
                    Max = deg[parent.top()];

                parent.pop();

                if(!parent.empty())
                    ++deg[parent.top()];
            }
            else if(ara[i] == ara[i+1])
            {
                ++deg[parent.top()];
                ++i;
            }
            else
                parent.push(ara[i]);
        }

        cout << Max << '\n';
    }

    return 0;
}
