/**
 * Hello 2020
 * Problem B - New Year and Ascent Sequence
 * TIME: 77 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

#define LIM 100000

typedef long long int ll;

typedef struct Type
{
    int min;
    bool mal;
}Type;

class Solution {
    int n, cnt_mal, i;
    Type arr[LIM];
    vector <int> mxs;
    ll ans;

    void ready(int idx)
    {
        int len, num, mn, mx;

        cin >> len >> num;

        mn = mx = num;
        arr[idx].mal = false;

        --len;
        while(len--)
        {
            cin >> num;

            if(num > mn)
                arr[idx].mal = true;

            mn = min(mn, num);
            mx = max(mx, num);
        }

        arr[idx].min = mn;

        if(arr[idx].mal) ++cnt_mal;
        else
            mxs.push_back(mx);

        return;
    }
public:
    ll solve()
    {
        cin >> n;
        
        cnt_mal = 0;
        for(i = 0; i < n; ++i)
            ready(i);
        
        ans = cnt_mal * ll(2*n - cnt_mal);

        sort(mxs.begin(), mxs.end());

        for(i = 0; i < n; ++i)
        {
            if(!arr[i].mal)
                ans += distance(upper_bound(mxs.begin(), mxs.end(), arr[i].min), mxs.end());
        }

        mxs.clear();

        return ans;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
 
    Solution sol;
    
    cout << sol.solve() << '\n';
 
    return 0;
}