/**
* UVa 11577 - Letter Frequency
* Time: 10 ms
* AUTHOR: Astik Roy
**/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int TC, fre[26], idx, Max;
    register int i;
    char str[201];

    cin >> TC;

    cin.ignore();
    while(TC--)
    {
        memset(fre, 0, sizeof(fre));

        cin.getline(str, 201);

        Max = 0;
        for(i = 0; str[i] != '\0'; ++i) {
            if(str[i] < 'a')
                str[i] += 32;

            if(str[i] >= 'a' && str[i] <= 'z') {
                idx = str[i] - 'a';

                if(++fre[idx] > Max)
                    Max = fre[idx];
            }
        }

        for(i = 0; i < 26; ++i)
            if(fre[i] == Max)
                cout << (char)('a' + i);
        cout << '\n';
    }

    return 0;
}
