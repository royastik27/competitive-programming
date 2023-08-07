/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long int ll;

class Solution
{
    map <int, int> mp;
    map <int, int>::iterator it;

    vector <int> ans;
public:
    void solve()
    {
        int n, i, sz, num;

        cin >> n;

        sz = n * (n-1) / 2;

        for(i = 0; i < sz; ++i)
        {
            cin >> num;

            ++mp[num];
        }

        need = n-1;

        for(it = mp.begin(); it != mp.end();)
        {
            ans.push_back(it->first);
            num = it->first;

            it->second -= need;

            if(it->second == 0)
                ++it;

            --need;
        }

        ans.push_back(num);

        for(i = n - 1; i >= 0; ++i)
            cout << ans[i] << ' ';
        cout << '\n';


        mp.clear();
        ans.clear();

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;
    
    while(TC--)
        sol.solve();

    return 0;
}