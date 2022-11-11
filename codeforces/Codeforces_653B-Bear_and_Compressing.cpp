/**
 * IndiaHacks 2016 - Online Edition (Div. 1 + Div. 2)
 * Problem B - Bear and Compressing
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector <char> vec[6];

    int build(char ch, int op)
    {
        if(!op) return 1;

        int i, idx = ch - 'a', sz = vec[idx].size(), ans = 0;

        for(i = 0; i < sz; ++i)
            ans += build(vec[idx][i], op-1);

        return ans;
    }
public:
    int solve()
    {
        int n, q, i, ans = 0;
        char ch;
        string str;

        cin >> n >> q;

        for(i = 0; i < q; ++i)
        {
            cin >> str >> ch;
            vec[ch - 'a'].push_back(str[0]);
        }
        
        return build('a', n-1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    
    cout << sol.solve() << '\n';

    return 0;
}