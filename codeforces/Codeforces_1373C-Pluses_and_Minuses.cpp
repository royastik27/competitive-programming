/**
 * Educational Codeforces Round 90 (Rated for Div. 2)
 * Problem C - Pluses and Minuses
 * Better than the editorial
 * Complexity of the author's code: O(n^2) [ whereas this code have O(n) complexity ]
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

class Solution{

public:
    ll solve()
    {
        string str;
        int i, len, curr;
        ll ans;
        char ch;

        cin >> str;

        ans = curr = 0;
        for(i = 0; (ch = str[i]) != '\0' ; ++i)
        {
            if(curr < 0) { curr = 0; ans += i+1; }
            else ++ans;

            if(ch == '+')
                ++curr;
            else --curr;
        }

        if(curr < 0) ans += i;
        
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