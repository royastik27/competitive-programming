/**
 * Codeforces Round #640 (Div. 4)
 * Problem D - Alice, Bob and Candies
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 200001

class Solution {

public:
    int solve()
    {
        int ans = 0, n, k, i;
        string str;

        cin >> n >> k >> str;

        int cnt = 0;
        for(i = 0; i < n; ++i)
        {
            if(str[i] == '1') break;

            ++cnt;
        }

        if(i < n)
            ans += cnt / (k + 1);
        else ans += cnt / k; // for all zero

        cnt = 0;

        for(; i < n; ++i)
        {
            if(str[i] == '1')
            {
                if(cnt)
                    ans += (cnt - k) / (k + 1);

                cnt = 0;
            }
            else ++cnt;
        }

        ans += cnt / (k + 1);

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