/**
 * Codeforces Round #562 (Div. 2)
 * Problem B - Pairs
 * TIME: 249 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
    int n, m;
    vector <bool> vis;
    vector < pair<int,int> > e;

    int count()
    {
        int i, x, cnt;
        pair <int, int> comp;

        for(i = 0; i < m && vis[i]; ++i);   // getting first unvisited

        if(i == m) return 0;    // nothing is left

        comp = e[i];    // chose first unvisited

        // counting
        set <int> a, b;

        for(i = i + 1; i < m; ++i)
        {
            if(!vis[i])
            {
                if(e[i].first == comp.first)
                    a.insert(e[i].second);
                else if(e[i].second == comp.first)
                    a.insert(e[i].first);
                    
                
                if(e[i].first == comp.second)
                    b.insert(e[i].second);
                else if(e[i].second == comp.second)
                    b.insert(e[i].first);
            }
        }

        // chossing x
        x = (b.size() > a.size() ? comp.second : comp.first);

        cnt = 0;
        for(i = 0; i < m; ++i)
            if(!vis[i] && (e[i].first == x || e[i].second == x))
            {
                ++cnt;
                vis[i] = true;
            }

        return cnt;
    }
public:
    bool solve()
    {
        int i, j;

        cin >> n >> m;

        while(m--)
        {
            cin >> i >> j;

            e.push_back({ i, j });
            vis.push_back(false);
        }
        m = e.size();
        
        return count() + count() == m;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    if(sol.solve()) cout << "YES\n";
    else cout << "NO\n";
 
    return 0;
}