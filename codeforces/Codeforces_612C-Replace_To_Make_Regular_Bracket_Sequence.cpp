/**
 * Educational Codeforces Round 4
 * Problem C - Replace To Make Regular Bracket Sequence
 * TIME: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <stack>
 
using namespace std;

class Solution
{
    string str;
    char ch;
    stack <char> st;
    int i, len, op;
public:
    void solve()
    {
        cin >> str;

        len = str.length();
        op = 0;
        for(i = 0; i < len; ++i)
        {
            ch = str[i];

            if(ch == '(' || ch == '{' || ch == '[' || ch == '<')
                st.push(ch);
            else if(st.empty())
            {
                st.push(ch);
                break;
            }
            else
            {
                if(ch == ')')
                    ch = '(';
                else if(ch == '}')
                    ch = '{';
                else if(ch == ']')
                    ch = '[';
                else ch = '<';

                if(st.top() != ch)
                    ++op;
                
                st.pop();
            }
        }

        if(st.size())
            cout << "Impossible\n";
        else cout << op << '\n';

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