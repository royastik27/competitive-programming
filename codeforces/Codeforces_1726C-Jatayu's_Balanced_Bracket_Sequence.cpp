/**
 * Codeforces Round #819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
 * Problem C - Jatayu's Balanced Bracket Sequence
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

#define LIM 200000

class Solution {
    int par[LIM];

    int Find(int x)
    {
        if(par[x] < 0)
            return x;

        return Find(par[x]);
    }

    void Union(int x, int y)
    {
        int parX = Find(x), parY = Find(y);

        if(parX == parY) return;

        if(par[parX] < par[parY])
        {
            par[parX] += par[parY];
            par[parY] = parX;
        }
        else
        {
            par[parY] += par[parX];
            par[parX] = parY;
        }
    }
public:
    int solve()
    {
        int n, i, top;
        string str;

        cin >> n >> str;
        n *= 2;

        memset(par, -1, n*sizeof(int));

        stack <int> st;
        st.push(0);

        for(i = 1; i < n; ++i)
        {

            if(str[i] == '(')
                st.push(i);
            else
            {
                top = st.top();
                st.pop();

                Union(top, i);

                if(top && str[top-1] == ')')
                    Union(top-1, top);
            }
        }

        int ans = 0;
        for(i = 0; i < n; ++i)
            if(par[i] < 0) ++ans;
            
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