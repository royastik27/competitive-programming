/**
 * Codeforces Round #739 (Div. 3)
 * Problem D - Make a Power of Two
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <sstream>

using namespace std;

typedef long long int ll;

#define LIM 60

class Solution
{
    string pow2[LIM + 1];
public:
    Solution()
    {
        ll num = 1;
        stringstream ss;

        for(int i = 0; i <= LIM; ++i)
        {
            ss << num;
            ss >> pow2[i];

            num *= 2;
            ss.clear();
        }

        return;
    }
    int solve()
    {
        string num;
        int i, j, k, res, ans = LIM;

        cin >> num;

        for(k = 0; k <= LIM; ++k)
        {
            i = j = res = 0;

            for(i = 0; num[i] != '\0'; ++i)
            {
                if(num[i] == pow2[k][j])
                    ++j;
                else ++res;
            }

            res += pow2[k].size() - j;

            ans = min(ans, res);
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