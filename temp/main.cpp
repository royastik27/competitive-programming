/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

#define INF 1000000000

class Solution
{
    int n;
    vector <pii> vec;

    bool check(int k)
    {
        int lpoint, rpoint, i;

        lpoint = rpoint = 0;

        for(i = 0; i < n; ++i)
        {
            lpoint = lpoint - k;
            rpoint = rpoint + k;

            if(rpoint < vec[i].first || lpoint > vec[i].second)
                return false;

            lpoint = max(lpoint, vec[i].first);
            rpoint = min(rpoint, vec[i].second);
        }

        return true;
    }
    
    int go()
    {
        int low = 0, high = INF, mid;

        while(low <= high)
        {
            mid = (low + high) / 2;

            if(check(mid))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
public:
    void solve()
    {
        int i, left, right;

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> left >> right;

            vec.push_back({left, right});
        }

        cout << go() << '\n';

        vec.clear();

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