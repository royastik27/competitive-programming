/**
* Codeforces Round #719 (Div. 3)
* Problem A - Do Not Be Distracted!
* Time: 15 ms
* AUTHOR: Astik Roy
**/


#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int TC, nDays, idx;
    char order[51], prev;
    bool done[26], isPossible;
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> nDays >> order;

        memset(done, 0, sizeof(done));

        isPossible = true;

        prev = order[0];
        done[(int)order[0] - 'A'] = true;

        for(i = 1; i < nDays; ++i)
        {
            if(order[i] == prev)
                continue;

            idx = (int)(order[i] - 'A');

            if(done[idx])
            {
                isPossible = false;
                break;
            }

            done[idx] = true;

            prev = order[i];
        }

        if(isPossible) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
