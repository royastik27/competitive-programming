/**
 * Codeforces Round #565 (Div. 3)
 * Problem C -  Lose it!
 * Time: 109 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

class Solution
{
    int hash(int n)
    {
        switch(n)
        {
            case 4:
                return 0;
            case 8:
                return 1;
            case 15:
                return 2;
            case 16:
                return 3;
            case 23:
                return 4;
            default:
                return 5;
        }
    }

public:
    int solve()
    {
        int n, el, i, cnt[6], idx;

        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        
        for(i = 0; i < n; ++i)
        {
            cin >> el;

            idx = hash(el);
            if(idx == 0) ++cnt[0];
            else if(cnt[idx-1] > 0) { --cnt[idx-1]; ++cnt[idx]; }
        }

        return n - cnt[5]*6;
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