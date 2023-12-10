/**
* Codeforces Round 112 (Div. 2)
* Problem B - Burning Midnight Oil
* TIME: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

class Solution
{
    int n, k;

    bool check(int v)
    {
        int quo, total = 0;
        ll denom = 1;

        while(quo = v / denom)
        {
            total += quo;
            denom *= k;
        }
        
        return (total >= n);
    }
public:
    void solve()
    {
        int low, high, mid;

        cin >> n >> k;

        low = 1; high = n;

        while(low <= high)
        {
            mid = (low+high) / 2;

            if(check(mid))
                high = mid - 1;
            else
                low = mid + 1;
        }

        cout << low << '\n';

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