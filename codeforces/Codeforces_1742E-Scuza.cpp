/**
 * Codeforces Round #827 (Div. 4)
 * Problem E - Scuza
 * TIME: 421 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>
 
using namespace std;
 
#define LIM 200001
 
class Solution {
    int arr[LIM], que[LIM];
    long long pre[LIM];
    map <int, int> mp;
    map <int, int>::iterator it;
public:
    void solve()
    {
        int n, q, i, cnt;
 
        cin >> n >> q;
 
        arr[0] = pre[0] = 0;
 
        for(i = 1; i <= n; ++i)
        {
            cin >> arr[i];
            pre[i] = pre[i-1] + arr[i];
        }
 
        for(i = 0; i < q; ++i)
        {
            cin >> que[i];
            mp[que[i]] = 0;
        }
 
        i = 1;
        cnt = 0;
        for(it = mp.begin(); it != mp.end(); )
        {
            if(i > n || arr[i] > it->first)
            {
                it->second = cnt;
                ++it;
            }
            else { ++cnt; ++i; }
        }
 
        for(i = 0; i < q; ++i)
            cout << pre[mp[que[i]]] << ' ';
        cout << '\n';
 
        mp.clear();
        
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