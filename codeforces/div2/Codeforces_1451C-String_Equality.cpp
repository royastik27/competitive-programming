/**
 * Codeforces Round #685 (Div. 2)
 * Problem C - String Equality
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
 
using namespace std;
 
class Solution
{
    string a, b;
    int n, x, freqA[26], freqB[26];
public:
    bool solve()
    {
        int i, smaller;

        cin >> n >> x >> a >> b;

        memset(freqA, 0, sizeof(freqA));
        memset(freqB, 0, sizeof(freqB));

        for(i = 0; i < n; ++i)
            ++freqA[int(a[i] - 'a')];

        for(i = 0; i < n; ++i)
            ++freqB[int(b[i] - 'a')];

        smaller = 0;

        for(i = 0; i < 26; ++i)
        {
            while(smaller && freqA[i] < freqB[i])
            {
                freqA[i] += x;
                smaller -= x;
            }

            while(freqA[i] > freqB[i])
            {
                freqA[i] -= x;
                smaller += x;
            }

            if(freqA[i] != freqB[i])
                return false;
        }

        return true;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        if(sol.solve()) cout << "Yes\n";
        else cout << "No\n";
 
    return 0;
}