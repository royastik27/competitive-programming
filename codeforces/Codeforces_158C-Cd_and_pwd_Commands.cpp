/**
 * VK Cup 2012 Qualification Round 1
 * Problem C - Cd and pwd commands
 * TIME: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
 
using namespace std;
 
class Solution
{
    vector <string> list;

    void display()
    {
        cout << '/';

        int i, n = list.size();
        for(i = 0; i < n; ++i)
            cout << list[i] << '/';
        cout << '\n';

        return;
    }
public:
    void solve()
    {
        int n, len, i;
        string cmd, inp, str;

        cin >> n;

        while(n--)
        {
            cin >> cmd;

            if(cmd[0] == 'p')
                display();
            else
            {
                cin >> inp;
                inp.push_back('/');

                if(inp[0] == '/')
                {
                    list.clear();
                    i = 1;
                }else i = 0;

                len = inp.length();
                for(; i < len; ++i)
                {
                    if(inp[i] == '/')
                    {
                        if(str == "..") list.pop_back();
                        else list.push_back(str);

                        str.clear();
                    }
                    else str.push_back(inp[i]);
                }
            }
        }
 
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