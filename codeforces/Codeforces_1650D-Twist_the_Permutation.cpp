/**
 * Codeforces Round #776 (Div. 3)
 * Problem D - Twist the Permutation
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <queue>
 
using namespace std;
 
#define LIM 2000
 
class Solution
{
    queue <int> que;
    int arr[LIM], ans[LIM];
public:
    void solve()
    {
        int n, i, cnt;
 
        cin >> n;
 
        for(i = 0; i < n; ++i) cin >> arr[i];
 
        for(i = n-1; i >= 0; --i)
            que.push(arr[i]);
 
        for(i = n; i >= 1; --i)
        {
            cnt = 0;
 
            while(que.front() != i)
            {
                ++cnt;
                que.push(que.front());
                que.pop();
            }
 
            if(cnt)
            {
                ans[i-1] = i - cnt;
            }
            else ans[i-1] = 0;
 
            que.pop();
        }
 
        for(i = 0; i < n; ++i) cout << ans[i] << ' ';
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