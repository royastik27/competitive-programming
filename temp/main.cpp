/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

class Solution
{
    int n;
    vector <int> a;
    vector <ll> presum;

    inline ll sum(int b, int e)
    {
        if(b > n || e < 1)
            return 0;

        return (presum[e] - presum[b-1]);
    }
public:
    void solve()
    {
        int alice, bob, i;
        ll ans;

        cin >> n >> alice >> bob;

        a.resize(n);

        for(i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end(), greater <int>());

        // presum.resize(n+1);
        presum.push_back(0);
        for(i = 0; i < n; ++i)
            presum.push_back(presum[i] + a[i]);        

        ans = sum(min(n, bob)+1, n) - sum(1, min(n, bob));

        for(i = 1; i <= alice; ++i)
            ans = max(ans, sum(min(n, i+bob)+1, n) - sum(1+i, min(n, i+bob)));

        cout << ans << '\n';

        presum.clear();

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