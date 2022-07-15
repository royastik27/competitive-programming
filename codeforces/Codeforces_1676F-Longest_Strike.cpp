/**
 * Codeforces Round #790 (Div. 4)
 * Problem F - Longest Strike
 * Time: 140 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    void solve()
    {
        int n, k, cnt, mx, el;
        map <int, int> mp;
        map <int, int>::iterator prev, curr;

        cin >> n >> k;

        while(n--)
        {
            cin >> el;
            ++mp[el];
        }

        // INITIALIZING
        int left, right, tempLeft;

        prev = mp.begin();
        cnt = 0;
        if(prev->second >= k) { ++cnt; tempLeft = left = right = prev->first; }
        mx = cnt;

        // POINTING TO CURRENT
        curr = prev; ++curr;

        // LOOP
        while(curr != mp.end())
        {
            if(curr->second < k)
                cnt = 0;
            else
            {
                if(curr->first == prev->first + 1)
                    ++cnt;
                else cnt = 1;

                if(cnt == 1) tempLeft = curr->first;
            }

            // UPDATING MAX
            if(cnt > mx)
            {
                left = tempLeft;
                right = curr->first;
                mx = cnt;
            }

            // MOVING
            prev = curr;
            ++curr;
        }

        // PRINTING RESULT
        if(!mx) cout << -1 << '\n';
        else cout << left << ' ' << right << '\n';

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