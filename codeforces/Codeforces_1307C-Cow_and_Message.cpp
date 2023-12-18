/**
* Codeforces Round 621 (Div. 1 + Div. 2)
* Problem C - Cow and Message
* TIME: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

typedef long long int ll;

class Solution
{
    inline int idx(char ch) { return ch - 'a'; }
public:
    void solve()
    {
        int n;
        string s;
        ll ans;

        cin >> s;

        n = s.length();

        if(n == 1)
            ans = 1;
        else if(n == 2)
            ans = s[0] == s[1] ? 2 : 1;
        else {
            int i, j, id, freq[26];
            ll mem[26][26];

            memset(freq, 0, sizeof(freq));
            memset(mem, 0, sizeof(mem));

            ++freq[idx(s[0])];

            for(i = 1; i < n; ++i) {

                id = idx(s[i]);

                for(j = 0; j < 26; ++j)
                    mem[j][id] += freq[j];

                ++freq[id];
            }

            ans = 0;

            // taking one
            for(i = 0; i < 26; ++i)
                ans = max(ans, (ll)freq[i]);

            // taking two
            for(i = 0; i < 26; ++i)
                for(j = 0; j < 26; ++j)
                    ans = max(ans, mem[i][j]);
        }

        cout << ans << '\n';

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}