/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    void solve()
    {
        int n, k, i, j;
        string str, ans;
        bool possible;

        cin >> str >> k;

        n = str.length();

        // checking validity
        possible = true;
        for(i = 2*k; i < n; ++i)
            if(str[i - 2*k] != str[i])
            {
                possible = false;
                break;
            }

        if(!possible) {
            cout << "-1\n";
            return;
        }

        // filling up the answer string
        j = 0; // ans[idx]
        for(i = k; i < n && j < k; ++i, ++j) // first substring
            ans.push_back(str[i]);

        // extra 0s
        while(j < k) {
            ans.push_back('0');
            ++j;
        }

        // second substring
        for(i = 0; i < k && j < n; ++i, ++j)
            ans.push_back(str[i]);

        // rests
        while(j < n) {
            ans.push_back(ans[j-k]);
            ++j;
        }

        cout << ans << '\n';

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