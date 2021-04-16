/**
* Codeforces Round #715 (Div. 2)
* Problem A - Average Height
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 2000

int main()
{
    int TC, nMembers, height, nEvens, nOdds, even[LIMIT], odd[LIMIT];
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> nMembers;

        nEvens = nOdds = 0;
        while(nMembers--)
        {
            cin >> height;

            if(height % 2 == 0)
                even[nEvens++] = height;
            else odd[nOdds++] = height;
        }

        for(i = 0; i+1 < nOdds; i += 2)
            cout << odd[i] << ' ' << odd[i+1] << ' ';

        if(nOdds % 2 == 1) cout << odd[nOdds-1] << ' ';

        for(i = 0; i+1 < nEvens; i += 2)
            cout << even[i] << ' ' << even[i+1] << ' ';

        if(nEvens % 2 == 1) cout << even[nEvens-1] << ' ';

        cout << '\n';
    }

    return 0;
}
