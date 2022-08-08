/**
* Educational Codeforces Round 130 (Rated for Div. 2)
* Problem C - awoo's Favorite Problem
* Time: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

#define LIM 100000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC, n, ptr[LIM], ptrB, ptrC, i, idx;
    char str[LIM + 1], ans[LIM + 1];
    bool impossible;

    cin >> TC;

    while(TC--)
    {
        cin >> n >> str >> ans;

        // PREPROCESSING
        ptrB = ptrC = impossible = 0;

        for(i = n - 1; i >= 0; --i)
        {
            switch(str[i])
            {
                case 'a':
                    ptrC = 0;
                    ptr[i] = ptrB;
                break;
                case 'b':
                    ptrB = i;
                    ptr[i] = ptrC;
                break;
                default:
                    ptrC = i;
                    ptrB = 0;
                    ptr[i] = 0;
            }
        }

        // CHECKING
        for(i = 0; i < n; ++i)
        {
            if(str[i] == ans[i])
                continue;
            else if(str[i]+1 == ans[i] && ptr[i])
            {
                idx = ptr[i];

                if(str[idx] == ans[i])
                {
                    str[idx] = str[i];
                    
                    if(str[idx] == str[idx+1])
                        ptr[idx] = ptr[idx+1];
                    else if(str[idx]+1 == str[idx+1])
                        ptr[idx] = idx+1;
                    else ptr[idx] = 0;
                }
                else { impossible = true; break; }
            }
            else
            {
                impossible = true;
                break;
            }
        }

        if(impossible) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
