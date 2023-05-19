/**
* UVA 775 - Hamiltonian Cycle
* Rank: 15 (Superb!)
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int ll;

#define LIM 257

class Solution
{
    vector <int> adj[LIM], ans;
    bool vis[LIM];
    int n;

    void extract_inp(string str, int * u, int * v)
    {
        int i, len = str.length();

        *u = *v = 0;

        for(i = 0; str[i] != ' '; ++i)
            *u = *u * 10 + int(str[i]-'0');

        for(i = i + 1; i < len; ++i)
            *v = *v * 10 + int(str[i]-'0');

        return;
    }

    bool dfs(int node = 1, int cnt = 0)
    {
        vis[node] = true;
        ++cnt;

        int i, sz = adj[node].size(), curr;

        if(cnt == n)    // if all node is visited
        {
            for(i = 0; i < sz; ++i)
            {
                curr = adj[node][i];

                if(curr == 1)
                {
                    ans.push_back(node);
                    return true;
                }
            }

            return false;
        }

        // for rest
        bool res;

        for(i = 0; i < sz; ++i)
        {
            curr = adj[node][i];

            if(!vis[curr])
            {
                res = dfs(curr, cnt);

                if(res)
                {
                    ans.push_back(node);
                    return true;
                }

                vis[curr] = false;
            }
        }

        return false;
    }
public:
    void solve(int n)
    {
        this->n = n;

        string str;
        int u, v, i;

        cin.ignore();
        while(true)
        {
            getline(cin, str);

            if(str == "%")
                break;

            extract_inp(str, &u, &v);

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        memset(vis, 0, n+1);

        if(!dfs()) cout << "N\n";
        else
        {
            int sz = ans.size();
            
            for(i = sz-1; i >= 0; --i) cout << ans[i] << ' ';
            cout << "1\n";

            ans.clear();
        }

        for(i = 1; i <= n; ++i)
            adj[i].clear();

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