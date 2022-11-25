/**
 * Codeforces Beta Round #92 (Div. 1 Only)
 * Problem A - Prime Permutation
 * TIME: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution{
    int mp[26] = {};
    string str;

    int find_max()
    {
        int mx = -1, mx_pos, i;

        for(i = 0; i < 26; ++i)
            if(mp[i] > mx)
            {
                mx = mp[i];
                mx_pos = i;
            }

        return mx_pos;
    }
public:
    void solve()
    {
        int i, j, len, pos, cnt;
        char fill;

        cin >> str;
        len = str.length();
        
        for(i = 0; i < len; ++i)
        {
            ++mp[int(str[i]-'a')];
            str[i] = 0;
        }

        pos = find_max();
        fill = 'a' + pos;

        for(i = 2; i <= len; i += 2)
        {
            if(!mp[pos])
            {
                cout << "NO\n";
                return;
            }

            str[i-1] = fill;
            --mp[pos];
        }

        for(i = 3; i <= len; i += 2)
        {
            if(str[i-1]) continue;

            cnt = 0;
            pos = -1;

            for(j = i; j <= len; j += i)
            {
                if(str[j-1]) pos = str[j-1] - 'a';
                else ++cnt;
            }

            if(pos == -1) pos = find_max();

            if(mp[pos] < cnt)
            {
                cout << "NO\n";
                return;
            }

            fill = 'a' + pos;
            for(j = i; j <= len; j += i)
                str[j-1] = fill;

            mp[pos] -= cnt;
        }

        str[0] = 'a' + find_max();

        cout << "YES\n" << str << '\n';        
        
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