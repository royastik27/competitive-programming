/**
 * Educational Codeforces Round 110 (Rated for Div. 2)
 * Problem C - Unstable String
 * Simpler than the editorial
 * TIME: 30 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;

typedef long long int ll;
 
class Solution
{

public:
    ll solve()
    {
        string str;
        char ch;
        int i, n;
        ll zero, one, ans, temp;

        cin >> str;
        n = str.length();

        zero = one = ans = 0;

        for(i = 0; i < n; ++i)
        {
            ch = str[i];

            if(ch == '0')
            {
                zero = one + 1;
                one = 0;
            }
            else if(ch == '1')
            {
                one = zero + 1;
                zero = 0;
            }
            else    // for '?'
            {
                temp = zero;
                zero = one + 1;
                one = temp + 1;
            }

            ans += max(one, zero);
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