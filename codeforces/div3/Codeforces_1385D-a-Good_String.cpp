/**
* Codeforces Round 656 (Div. 3)
* Problem D - a-Good String
* TIME: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

class Solution
{
    int n;
    string str;

    int go(int b, int e, char ch = 'a')
    {
        // base case
        if(b == e)
            return str[b] != ch;
        
        // other cases
        int mid = (b+e) / 2, firstHalf, secondHalf, i;

        firstHalf = secondHalf = 0;

        for(i = b; i <= mid; ++i)
            if(str[i] != ch) ++firstHalf;

        for(; i <= e; ++i)
            if(str[i] != ch) ++secondHalf;

        return min(firstHalf + go(mid+1, e, ch+1), secondHalf + go(b, mid, ch+1));
    }
public:
    void solve()
    {
        cin >> n >> str;

        cout << go(0, n-1) << '\n';

        return;
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
        sol.solve();

    return 0;
}