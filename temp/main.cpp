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
        int point = 0, i;

        for(i = 0; i < n; ++i)
        {
            if(point + k < vec[i].first)
                return false;

            point = min(point + k, vec[i].second);
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

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        sol.solve();

    return 0;
}