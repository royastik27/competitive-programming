/**
 * Codeforces Round 260 (Div. 2)
 * Problem C - Boredom
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    ll solve()
    {
        int n, num;
        map <int, int> mp;
        map <int, int>::iterator curr, prev;
        ll mx, ans, ans1, ans2, ans3, res;

        cin >> n;

        while(n--)
        {
            cin >> num;

            ++mp[num];
        }

        prev = curr = mp.begin();

        // considering first smallest element
        mx = ll(curr->first) * curr->second;
        ans1 = mx;
        ans = ans2 = ans3 = 0;

        ++curr;

        while(curr != mp.end())
        {
            if(curr->first != prev->first + 1) // resetting
            {
                ans += mx;
                ans1 = ans2 = ans3 = mx = 0;
            }

            res = ll(curr->first) * curr->second + max(ans2, ans3);

            ans3 = ans2;
            ans2 = ans1;
            ans1 = res;

            mx = max(mx, res);

            ++prev;
            ++curr;
        }

        ans += mx;
        
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    cout << sol.solve() << '\n';

    return 0;
}
