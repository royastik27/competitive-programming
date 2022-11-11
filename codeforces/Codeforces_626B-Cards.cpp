/**
 * 8VC Venture Cup 2016 - Elimination Round
 * Problem B - Cards
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2

class Solution {

    int hash(char ch)
    {
        switch(ch)
        {
            case 'R':
                return RED;
            case 'G':
                return GREEN;
            default:
                return BLUE;
        }
    }
    char reHash(int idx)
    {
        switch(idx)
        {
            case RED:
                return 'R';
            case GREEN:
                return 'G';
            default:
                return 'B';
        }
    }

    char mix(int idx1, int idx2)
    {
        for(int i = 0; i < 3; ++i)
            if(i != idx1 && i != idx2)
                return reHash(i);

        return 'F';
    }
public:
    void solve()
    {
        int n, color[3] = {}, i, cnt;
        string str;

        cin >> n >> str;

        for(i = 0; i < n; ++i)
            ++color[hash(str[i])];

        cnt = 0;
        for(i = 0; i < 3; ++i)
            if(color[i]) ++cnt;

        if(cnt == 1)
        {
            for(i = 0; i < 3; ++i)
                if(color[i]) cout << reHash(i) << '\n';
        }
        else if(cnt == 2)
        {
            vector <pair <int, int> > ans;
            int mn, mx;

            for(i = 0; i < 3; ++i)
                if(color[i]) ans.push_back({i, color[i]});

            if(ans[0].second < ans[1].second)
            {
                mn = ans[0].first;
                mx = ans[1].first;
            }
            else { mn = ans[1].first; mx = ans[0].first; }

            if(color[mn] == 1)
            {
                if(color[mx] == 1)
                    cout << mix(mn, mx) << '\n';
                else
                {
                    char ans1 = reHash(mn), ans2 = mix(mn, mx);

                    cout << min(ans1, ans2) << max(ans1, ans2) << '\n';
                }
            }
            else cout << "BGR\n";
        }
        else cout << "BGR\n";
        
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}