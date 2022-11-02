/**
 * Codeforces Round #623 (Div. 2, based on VK Cup 2019-2020 - Elimination Round, Engine)
 * Problem B - Homecoming
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

class Solution {

public:
    int solve()
    {
        int a, b, p, i, sz, ans;
        ll curr;
        string str;

        cin >> a >> b >> p >> str;

        sz = str.length();

        curr = (str[sz-2] == 'A') ? a : b;
        ans = (curr <= p) ? sz - 1 : sz;

        for(i = sz - 3; i >= 0; --i)
        {
            if(str[i] != str[i+1])
                curr += (str[i] == 'A') ? a : b;

            if(curr <= p) ans = i+1;
        }
        
        return ans;
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
        cout << sol.solve() << '\n';

    return 0;
}
