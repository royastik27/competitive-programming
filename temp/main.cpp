/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef long long int ll;

class Solution
{
    map < pair<int,int>, int> mp;
    map < pair<int,int>, int>::iterator it;

    pair < map < pair<int,int>, int>::iterator, bool> check;
public:
    void solve()
    {
        int n, D, K, i, d, a, b, ans;
        string s;

        cin >> n >> s;

        D = K = 0;
        
        for(i = 0; i < n; ++i) {
            if(s[i] == 'D') ++D;
            else            ++K;

            d = __gcd(D, K);
            a = D / d;
            b = K / d;

            check = mp.insert({ {a, b}, 1 });

            if(check.second)
                ans = 1;
            else {
                it = check.first;

                ans = 1 + it->second;
                ++it->second;
            }
            
            cout << ans << ' ';
        }
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