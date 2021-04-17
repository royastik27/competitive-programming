/**
* Codeforces Round #578 (Div. 2)
* Problem A - Hotelier
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char rooms[] = "0000000000";
    int nEvents;
    char operation[100001];
    register int i, j;

    cin >> nEvents >> operation;

    for(i = 0; i < nEvents; ++i)
    {
        switch(operation[i])
        {
        case 'L':
            for(j = 0; ; j++)
            {
                if(rooms[j] == '0')
                {
                    rooms[j] = '1';
                    break;
                }
            }
            break;
        case 'R':
            for(j = 9; ; --j)
            {
                if(rooms[j] == '0')
                {
                    rooms[j] = '1';
                    break;
                }
            }
            break;
        default:
                rooms[(int)operation[i]-48] = '0';
        }
    }

    cout << rooms << '\n';

    return 0;
}
