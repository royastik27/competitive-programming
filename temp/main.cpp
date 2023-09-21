/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;

class Solution
{
    ll cum;
    vector <int>::iterator UB;

    ll water(int height)
    {
        UB = lower_bound(vec.begin(), vec.end(), height);

        int idx = distance(vec.begin(), vec.end());

        if(idx == 0)
            return 0;

        return cum[idx-1] - ll(height) * idx;
    }
public:
    void solve()
    {
        cin >> n >> x;

        for(i = 0; i < n; ++i)
        {
            cin >> num;

            vec.push_back(num);
        }

        sort(vec.begin(), vec.end());

        cum.push_back(vec[0]);
        for(i = 1; i < n; ++i)
            cum.push_back(vec[i] + cum[i-1]);
        
        low = 1;
        high = *max_element(vec.begin(), vec.end());

        ans = 1;
        while(low <= high)
        {
            mid = (low + high) / 2;

            if(water(mid) <= x)
            {
                ans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }

        cout << ans << '\n';

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