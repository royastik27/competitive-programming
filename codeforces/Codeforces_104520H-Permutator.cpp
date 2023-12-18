/**
* Teamscode Summer 2023 Contest
* Problem H - Permutator
* TIME: N/A
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    void solve()
    {
        int n, i;
        ll sum;
        vector <int> a, b;
        vector <ll> weight;

        cin >> n;

        a.resize(n);
        b.resize(n);

        for(i = 0; i < n; ++i)
            cin >> a[i];

        for(i = 0; i < n; ++i)
            cin >> b[i];

        // processing
        for(i = 0; i < n; ++i)
            weight.push_back(ll(i+1) * (n-i) * a[i]);

        sort(weight.begin(), weight.end());
        sort(b.begin(), b.end(), greater <int>());

        sum = 0;
        for(i = 0; i < n; ++i)
            sum += weight[i] * b[i];

        cout << sum << '\n';

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}