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
    // cin.tie(NULL);

    int TC, n, ptr[LIM], ptrB, ptrC, i;
    char str[LIM + 1], ans[LIM + 1];

    cin >> TC;

    while(TC--)
    {
        cin >> n >> str >> ans;

        // PREPROCESSING
        ptrB = ptrC = 0;

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

        cout << "Preprocessed Result:\n";
        for(i = 0; i < n; ++i)
            cout << ptr[i] << ' ';
        cout << '\n';
    }

    return 0;
}
