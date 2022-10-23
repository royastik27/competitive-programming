/**
 * Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
 * Problem B - Reverse String
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;

#define LIM 500
 
class Solution {    
    string str, pat;
    int sz1, sz2;
public:
    bool solve()
    {
        cin >> str >> pat;
        sz1 = str.length(); sz2 = pat.length();

        int i, j, k, t, cnt, n;

        for(i = 0; i < sz1; ++i)        // right lower bound
        {
            for(j = i; j < sz1; ++j)    // right upper bound
            {
                cnt = 0;
                // go right and match
                n = j - i + 1;
                for(k = 0; k < n && k < sz2; ++k)
                {
                    // cout << str[k+i];
                    if(str[k + i] == pat[k]) ++cnt;
                }

                // go left and match
                for(t = k+i-2;t >= 0 && k < sz2; ++k, --t)
                {
                    // cout << str[t];
                    if(str[t] == pat[k]) ++cnt;
                }
                // cout << '\n';

                if(cnt == sz2) return true;
            }
        }
        
        return false;
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
        if(sol.solve()) cout << "YES\n";
        else cout << "NO\n";
    
    return 0;
}