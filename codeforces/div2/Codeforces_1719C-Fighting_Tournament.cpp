/**
 * Codeforces Round #814 (Div. 2)
 * Problem C - Fighting Tournament
 * TIME: 77 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
 
using namespace std;

#define LIM 100000
 
class Solution {
    deque <int> que;
    vector <int> win;
    vector <int>::iterator UB, LB;
    int arr[LIM], n, q, k, a, b, i, sen, ans, mx;
public:
    void solve()
    {
        cin >> n >> q;

        mx = 0;
        for(i = 0; i < n; ++i)
        {
            cin >> arr[i];
            que.push_back(arr[i]);

            if(arr[i] > mx)
                mx = arr[i];
        }

        for(i = 1; i < n; ++i)
        {
            a = que.front();
            que.pop_front();

            b = que.front();
            que.pop_front();

            if(a > b)
            {
                win.push_back(a);
                que.push_front(a);

                que.push_back(b);
            }
            else
            {
                win.push_back(b);
                que.push_front(b);

                que.push_back(a);
            }
        }

        while(q--)
        {
            cin >> i >> k;

            sen = min(n-1, k);

            LB = lower_bound(win.begin(), win.begin() + sen, arr[i-1]);

            UB = upper_bound(win.begin(), win.begin() + sen, arr[i-1]);

            ans = distance(LB, UB);

            if(arr[i-1] == mx)
                ans += max(k - n + 1, 0);

            cout << ans << '\n';
        }

        que.clear();
        win.clear();

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