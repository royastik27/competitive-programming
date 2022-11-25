/**
 * Codeforces Round #827 (Div. 4)
 * Problem F - Smaller
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

typedef long long int ll;

class Solution
{
    ll s[2][26];
public:
    void solve()
    {
        int m, idx, k, sz, i;
        ll len[2];
        bool notA[2];
        string x;
        memset(s, 0, sizeof(s));

        s[0][0] = s[1][0] = len[0] = len[1] = 1;
        notA[0] = notA [1] = false;

        cin >> m;

        while(m--)
        {
            cin >> idx >> k >> x;
            --idx;

            // updating length
            sz = x.length();
            len[idx] += ll(k)*sz;

            // updating map
            for(i = 0; i < sz; ++i)
            {
                if(x[i] != 'a') notA[idx] = true;
                ++s[idx][int(x[i]-'a')];
            }

            if(!notA[0] && !notA[1])
                cout << (len[0] < len[1] ? "YES\n" : "NO\n");
            else if(notA[1])
                cout << "YES\n";
            else cout << "NO\n";
        }

        return;
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
        sol.solve();

    return 0;
}