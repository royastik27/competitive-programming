/**
* Codeforces Round 863 (Div. 3)
* Problem E - Living Sequence
* TIME: 577 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

class Solution
{
    ll mem[13];
    vector <int> digits;

    ll rest_n()
    {
        ll res = 0;

        int i, sz = digits.size();

        for(i = sz - 1; i >= 0; --i)
            res = res * 10 + digits[i];

        return res;
    }

    ll has4(ll n)
    {
        int dig, i;
        ll res, power_10;

        res = 0;
        power_10 = 1;

        for(i = 0; n; ++i)
        {
            dig = n % 10;

            if(dig < 4)
                res = dig * mem[i] + res;
            else if(dig == 4)
                res = dig * mem[i] + rest_n() + 1;
            else
                res = (dig-1) * mem[i] + power_10 + res;

            n /= 10;
            power_10 *= 10;
            digits.push_back(dig);
        }

        digits.clear();

        return res;
    }
public:
    Solution()
    {
        int i;
        ll power_10;

        mem[0] = 0;

        power_10 = 1;

        for(i = 1; i <= 12; ++i)
        {
            mem[i] = mem[i-1] * 9 + power_10;
            power_10 *= 10;
        }

        return;
    }
    void solve()
    {
        ll n, num, has, th;

        cin >> n;

        num = n;

        has = has4(num);
        th = num - has;

        while(th != n)
        {
            num += n - th;

            has = has4(num);
            th = num - has;
        }

        cout << num << '\n';

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