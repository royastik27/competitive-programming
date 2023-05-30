/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long int ll;

#define LIM 1000

class Solution
{
    int arr[LIM];
    ll ans[LIM];
public:
    void solve()
    {
        int n, i, grp, cnt, j, idx;
        ll sum;

        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> arr[i];

        sort(arr, arr+n);

        cin >> grp >> sum;

        if(n % grp)
        {
            cout << "NO\n";
            return;
        }

        cnt = n / grp;

        memset(ans, 0, sizeof(ans));
        idx = -1;

        bool front = true;
        for(i = 0; i < cnt; ++i)
        {
            if(front)
            {
                for(j = 0; j < grp; ++j)
                    ans[j] += arr[++idx];
            }
            else
            {
                for(j = grp - 1; j >= 0; --j)
                    ans[j] += arr[++idx];
            }            

            front ^= 1;       
        }

        for(i = 1; i < grp; ++i)
        {
            if(ans[i] != ans[0])
            {
                cout << "NO\n";
                return;
            }
        }

        cout << "YES\n";

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}