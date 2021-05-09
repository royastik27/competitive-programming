/**
* Codeforces Round #627 (Div. 3)
* Problem C - Frog Jumps
* Time: 46 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int TC, jump, Max;
    char str[200001];
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> str;

        Max = 1;
        jump = 0;
        for(i = 0; str[i] != '\0'; ++i)
        {
            ++jump;

            if(str[i] == 'R')
            {
                if(jump > Max)
                    Max = jump;

                jump = 0;
            }
        }
        // visiting n+1 th cell
        ++jump;

        if(jump > Max)
            Max = jump;

        cout << Max << '\n';
    }

    return 0;
}
