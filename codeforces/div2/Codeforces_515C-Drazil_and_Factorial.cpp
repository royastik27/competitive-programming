/**
 * Codeforces Round #292 (Div. 2)
 * Problem C - Drazil and Factorial
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
 
using namespace std;

class Solution
{

public:
    void solve()
    {
        int n, freq[8], i, j, dig;
        string str;
        memset(freq, 0, sizeof(freq));

        cin >> n >> str;

        for(i = 0; i < n; ++i)
        {
            if(str[i] == '0')
                continue;

            dig = int(str[i]-'0');

            switch(dig)
            {
                case 4:
                    freq[2] += 2;
                    ++freq[3];
                break;

                case 6:
                    ++freq[3];
                    ++freq[5];
                break;

                case 8:
                    freq[2] += 3;
                    ++freq[7];
                break;

                case 9:
                    freq[3] += 2;
                    ++freq[2];
                    ++freq[7];
                break;

                default:
                    ++freq[dig];
            }
        }

        for(i = 7; i > 1; --i)
        {
            for(j = 0; j < freq[i]; ++j)
                cout << i;
        }
        cout << '\n';

        return;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    
    sol.solve();
 
    return 0;
}