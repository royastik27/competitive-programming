/**
 * Educational Codeforces Round 117 (Rated for Div. 2)
 * Problem C - Chat Ban
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

class Solution
{
    int k;

    ll emote(int msg)
    {
        if(msg > k)
        {
            int diff = msg - k;
            return k*ll(k+1)/2 + ll(diff)*(2*k-diff-1)/2;
        }

        return msg*ll(msg+1)/2;
    }
public:
    int solve()
    {
        int low, high, mid;
        ll x, cnt;

        cin >> k >> x;

        low = 1; high = 2*k - 1;

        while(low <= high)
        {
            mid = (ll(low)+high) / 2;

            cnt = emote(mid);

            if(cnt == x)
            {
                low = mid;
                break;
            }
            else if(cnt < x)
                low = mid+1;
            else
                high = mid-1;
        }

        return min(low, 2*k-1);
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
        cout << sol.solve() << '\n';

    return 0;
}