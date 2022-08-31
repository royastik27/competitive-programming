/**
 * Codeforces Round #817 (Div. 4)
 * Problem B - Colourblindness
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution {

public:
    bool solve()
    {
        int n, i;
        string str;
        char ch;

        cin >> n >> str;

        int cnt = n;
        for(i = 0; i < n; ++i)
        {
            cin >> ch;

            if(ch == 'R' && str[i] != 'R') --cnt;
            else if(ch != 'R' && str[i] == 'R') --cnt;
        }

        return (cnt == n);
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