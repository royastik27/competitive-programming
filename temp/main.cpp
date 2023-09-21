/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

class Solution
{
    char grid[10][10];

    bool ok(int i, int j)
    {
        return (grid[i][j] == 'X');
    }

    int go(int bod)
    {
        int ans = 0, i, j;

        for(i = bod+1; i <= 8-bod; ++i)
            if(ok(bod, i))
                ans += (bod+1);
        
        for(i = bod+1; i <= 8-bod; ++i)
            if(ok(9-bod, i))
                ans += (bod+1);

        for(i = bod; i <= 9 - bod; ++i)
            if(ok(i, bod))
                ans += (bod+1);

        for(i = bod; i <= 9 - bod; ++i)
            if(ok(i, 9-bod))
                ans += (bod+1);

        return ans;

    }
public:
    void solve()
    {

        for(i = 0; i < 10; ++i)
            for(j = 0; j < 10; ++j)
                cin >> grid[i][j];

        ans = 0;
        for(i = 0; i < 5; ++i)
            ans += go(i);

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