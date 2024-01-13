/**
* Good Bye 2020
* Problem D - 13th Labour of Heracles
* TIME: 265 ms
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
    vector <pii> arr; // { weight, degree }
public:
    void solve()
    {
        int n, i, j, u, v, extra;
        ll sum;

        cin >> n;

        arr.resize(n+1);

        sum = 0;
        for(i = 1; i <= n; ++i) {
            cin >> arr[i].first;
            sum += arr[i].first;
            
            arr[i].second = 0;
        }

        for(i = 1; i < n; ++i) {
            cin >> u >> v;

            ++arr[u].second;
            ++arr[v].second;
        }

        sort(++arr.begin(), arr.end(), greater<pii>());

        cout << sum << ' ';
        for(i = 1; i <= n; ++i) {
            
            if(arr[i].second == 1)
                continue;
            
            extra = arr[i].second - 1;
            for(j = 0; j < extra; ++j)
                cout << (sum += arr[i].first) << ' ';
        }
        cout << '\n';

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