/**
* Educational Codeforces Round 161 (Rated for Div. 2)
* Problem E - Increasing Subsequences
* TIME: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

class Solution
{
    bitset <61> bits;
    vector <int> power, ans;
public:
    void solve()
    {
        int i, sz;
        ll x;

        cin >> x;

        bits = bitset <61>(x);

        for(i = 60; i >= 0; --i)
            if(bits[i]) {
                power.push_back(i);
            }
        
        for(i = 0; i < power[0]; ++i)
            ans.push_back(i);

        sz = power.size();
        for(i = 1; i < sz; ++i)
            ans.push_back(power[i]);

        sz = ans.size();
        cout << sz << '\n';
        for(i = 0; i < sz; ++i)
            cout << ans[i] << ' ';
        cout << '\n';

        power.clear();
        ans.clear();        

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