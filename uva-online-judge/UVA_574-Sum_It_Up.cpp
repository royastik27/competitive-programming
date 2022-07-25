/**
 * UVA 574 - Sum It Up
 * RANK: 2674 out of 9371
 * TIME: 0.000 sec
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LIM 12

class Solution {
    int n, total, arr[LIM];
    vector < vector <int> > ans;
public:
    void go(int state = 0, int sum = 0, int mask = 0)
    {
        if(sum == total)
        {
            // GETTING RESULT
            vector <int> ans;
            int match = 0, idx = 0, i;

            for(i = 0; i < n; ++i)
            {
                if(mask & (1 << i))
                    ans.push_back(arr[i]);
            }

            this->ans.push_back(ans);            
            
            return;
        }
        if(state == n) return;

        // RECURSIVE CALLS
        go(state+1, sum + arr[state], mask | (1 << state));
        go(state+1, sum, mask);

        return;
    }
    void solve(int total, int n)
    {
        this->n = n;
        this->total = total;

        int i;
        for(i = 0; i < n; ++i) cin >> arr[i];

        cout << "Sums of " << total << ":\n";

        go();

        if(!ans.size()) cout << "NONE\n";
        else
        {
            sort(ans.begin(), ans.end(), greater< vector<int> >());

            // FIRST ANS
            cout << ans[0][0];
            for(i = 1; i < ans[0].size(); ++i)
                cout << '+' << ans[0][i];
            cout << '\n';

            int j, sz;
            for(i = 1; i < ans.size(); ++i)
            {
                int match = 0;

                sz = min(ans[i].size(), ans[i-1].size());

                for(j = 0; j < sz; ++j)
                    if(ans[i][j] == ans[i-1][j]) ++match;

                if(match != ans[i].size())
                {
                    cout << ans[i][0];

                    for(j = 1; j < ans[i].size(); ++j)
                        cout << '+' << ans[i][j];
                    cout << '\n';
                }
            }

            ans.clear();
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    int total, n;

    while(1)
    {
        cin >> total >> n;

        if(!n) break;

        sol.solve(total, n);
    }
    
    return 0;
}