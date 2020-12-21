/**
* UVA 11292 - Dragon of Loowater
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <algorithm>

#define LIMIT 20000

using namespace std;

int main()
{
    int n_heads, n_knights, i, j, res;
    int head[LIMIT], knight[LIMIT];

    while(1)
    {
        cin >> n_heads >> n_knights;

        if(!n_heads && !n_knights) break;

        for(i = 0; i<n_heads; i++)
            cin >> head[i];
        for(i = 0; i<n_knights; i++)
            cin >> knight[i];

        sort(head, head+n_heads);
        sort(knight, knight+n_knights);

        res = 0;
        for(i = 0, j = 0; i<n_heads; j++)
        {
            if(j > n_knights-1)
                break;
            else if(head[i] > knight[j])
                continue;
            else
            {
                res+=knight[j];
                i++;
            }
        }

        if(i == n_heads)
            cout << res << '\n';
        else
            cout << "Loowater is doomed!\n";
    }

    return 0;
}
