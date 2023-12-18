/**
* Codeforces Round 797 (Div. 3)
* Problem E - Price Maximization
* TIME: 93 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

class Solution
{
    vector <int> v;
public:
    void solve()
    {
        int n, k, i, j, num, quo, rem;
        ll sum;

        cin >> n >> k;

        sum = 0;
        for(i = 0; i < n; ++i)
        {
            cin >> num;

            quo = num / k;
            sum += quo;

            rem = num - quo * k;

            if(rem) v.push_back(rem);
        }

        sort(v.begin(), v.end());

        i = 0; j = v.size()-1;
        while(i < j)
        {
            if(v[i] + v[j] < k)
                ++i;
            else {
                ++sum;
                ++i;
                --j;
            }
        }

        cout << sum << '\n';

        v.clear();

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