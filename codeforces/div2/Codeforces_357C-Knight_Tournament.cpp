/**
* Codeforces Round 207 (Div. 2)
* Problem C - Knight Tournament
* TIME: 327 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    void solve()
    {
        int n, m, i, left, right, xi;
        vector <int> winner;
        set <int> s;
        set <int>::iterator it1, it2, to_del;

        cin >> n >> m;

        winner.resize(n+1);

        for(i = 1; i <= n; ++i)
            s.insert(i);

        while(m--) {
            cin >> left >> right >> xi;

            it1 = s.lower_bound(left);
            it2 = s.upper_bound(right);

            while(it1 != it2) {
                if(*it1 == xi) {
                    winner[xi] = 0;
                    ++it1;
                }
                else {
                    winner[*it1] = xi;
                    to_del = it1;
                    ++it1;
                    s.erase(to_del);
                }
            }
        }

        for(i = 1; i <= n; ++i)
            cout << winner[i] << ' ';
        cout << '\n';

        // assuming there is no case for multiple 0s

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    sol.solve();

    return 0;
}