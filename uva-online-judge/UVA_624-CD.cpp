/**
 * UVA 624 - CD
 * DP Solution of Backtracking Problem
 * RANK: 1669 out of 20005
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b)
{
    return a.second < b.second;
}

class Solution {    
    
public:
    void solve(int n)
    {
        int nTracks, i, j, el;
        vector < pair <int, int> > track;

        // INPUT
        cin >> nTracks;

        for(i = 0; i < nTracks; ++i)
            { cin >> el; track.push_back(make_pair(el, i+1)); }

        sort(track.begin(), track.end());
        
        // GENERATING TABLE
        vector <int> dp(n+1, 0);
        dp[0] = 22;

        // // PRINTING TRACKS
        // cout << "Tracks: ";
        // for(int i = 0; i < track.size(); ++i)
        //     cout << track[i].first << ' ';
        // cout << '\n';

        for(i = 0; i < nTracks; ++i)
        {
            for(j = track[i].first; j <= n; ++j)
            {
                if(dp[j]) continue;

                else if(dp[j - track[i].first] && dp[j - track[i].first] != i+1)
                    dp[j] = i + 1;
            }

            // cout << "For " << track[i].first << "\n";
            // for(int k = 0; k <= n; ++k)
            //     cout << dp[k] << ' ';
            // cout << '\n';
        }

        // // DP TABLE PRINTING
        // cout << "\nDP:\n";
        // for(i = 0; i <= n; ++i)
        //     cout << dp[i] << ' ';
        // cout << "\n\n";

        // GETTING RESULT
        int curr = n, sum = 0;
        vector < pair <int, int> > ans;

        while(curr != 0)
        {
            if(!dp[curr])
                --curr;
            else
            {
                el = track[dp[curr] - 1].first;
                ans.push_back(make_pair(el, track[dp[curr] - 1].second));

                sum += el;
                curr = curr - el;
            }
        }

        sort(ans.begin(), ans.end(), cmp);
        for(vector < pair <int, int> >::iterator it = ans.begin(); it != ans.end(); ++it)
            cout << it->first << ' ';

        cout << "sum:" << sum << '\n';
        
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    int n;

    while(cin >> n)
        sol.solve(n);
    
    return 0;
}