/**
* Codeforces Round 661 (Div. 3)
* Problem D - Binary String To Subsequences
* TIME: 46 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

class Solution
{
    vector <int> zero, one, ans;
public:
    void solve()
    {
        int n, i, mx;
        string str;

        cin >> n >> str;

        mx = 0;
        for(i = 0; i < n; ++i)
        {
            if(str[i] == '0') {
                // find one
                if(one.size()) {
                    ans.push_back(one.back());

                    zero.push_back(one.back());
                    one.pop_back();
                }
                // assing new
                else {
                    ans.push_back(++mx);
                    zero.push_back(mx);
                }
            }
            else {
                // find zero
                if(zero.size()) {
                    ans.push_back(zero.back());

                    one.push_back(zero.back());
                    zero.pop_back();
                }
                // assign new
                else {
                    ans.push_back(++mx);
                    one.push_back(mx);
                }
            }
        }
        
        cout << mx << '\n';
        for(i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';

        zero.clear();
        one.clear();
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