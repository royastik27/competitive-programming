/**
* Codeforces Round 640 (Div. 4)
* Problem E - Special Elements
* TIME: 296 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define LIM 8000

class Solution
{
    int n, a[LIM];

    bool check(int b, int e, int val)
    {
        if(b >= e)
            return false;

        int i, j, sum = 0;

        for(i = j = b; j <= e; ++j)
        {
            sum += a[j];

            while(sum > val)
            {
                sum -= a[i];
                ++i;
            }

            if(sum == val && j - i > 0)
                return true;
        }

        return false;        
    }
public:
    void solve()
    {
        int i, cnt;

        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> a[i];

        cnt = 0;
        for(i = 0; i < n; ++i)
        {
            if(check(0, i-1, a[i]) || check(i+1, n-1, a[i]))
                ++cnt;
        }

        cout << cnt << '\n';

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