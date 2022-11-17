/**
 * Codeforces Round #669 (Div. 2)
 * Problem B - Big Vova
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    vector <int> vec, ans;
    vector <int>::iterator it, mx_it;
public:
    void solve()
    {
        int n, el, i, mx, gcd;

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> el;
            vec.push_back(el);
        }

        mx_it = max_element(vec.begin(), vec.end());
        mx = *mx_it;

        ans.push_back(mx);
        vec.erase(mx_it);

        gcd = mx;

        while(!vec.empty())
        {
            mx = 0;

            for(it = vec.begin(); it != vec.end(); ++it)
            {
                if((el = __gcd(gcd, *it)) > mx)
                {
                    mx = el;
                    mx_it = it;
                }
            }

            ans.push_back(*mx_it);
            vec.erase(mx_it);

            gcd = mx;
        }

        for(i = 0; i < n; ++i) cout << ans[i] << ' ';
        cout << '\n';

        ans.clear();
        
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