/**
 * Codeforces Round #775 (Div. 2, based on Moscow Open Olympiad in Informatics)
 * Problem C - Weird Sum
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

#define LIM 100000

class Solution
{
    pair < vector <int>, vector <int> > vec[LIM + 1];
    ll ans;

    void get_ans(vector <int> v)
    {
        sort(v.begin(), v.end());

        int i, sz = v.size();
        ll prev = 0, curr;

        for(i = 1; i < sz; ++i)
        {
            curr = ll(v[i] - v[i-1]) * i;

            ans += prev += curr;
        }

        return;
    }
public:
    ll solve()
    {
        int n, m, i, j, color;

        cin >> n >> m;

        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
            {
                cin >> color;

                vec[color].first.push_back(i);
                vec[color].second.push_back(j);
            }

        ans = 0;
        for(i = 1; i <= LIM; ++i)
        {
            get_ans(vec[i].first);
            get_ans(vec[i].second);
        }

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