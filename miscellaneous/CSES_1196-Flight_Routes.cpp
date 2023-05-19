/**
* CSES 1196 - Flight_Routes
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <queue>

using namespace std;

typedef long long int ll;
typedef pair <ll, int> pii;

#define LIM 100001

class Solution
{

public:
    void solve()
    {
        int n, m, k, i, j, c, sz, curr_node, adj_node;
        ll curr_dist, dist;
        vector < pair <int,int> > adj[LIM];
        priority_queue < pii, vector<pii>, greater<pii> > pq;
        pii temp;

        // input
        cin >> n >> m >> k;

        while(m--)
        {
            cin >> i >> j >> c;

            adj[i].push_back({ j, c });
        }

        // processing
        vector <ll> ans;
        vector <int> freq(n+1, 0);

        pq.push({ 0, 1 });

        while(freq[n] < k)
        {
            temp = pq.top();
            curr_dist = temp.first;
            curr_node = temp.second;
            pq.pop();

            if(++freq[curr_node] > k)   // optimization 1
                continue;

            if(curr_node == n)
                ans.push_back(curr_dist);

            sz = adj[curr_node].size();

            for(i = 0; i < sz; ++i)
            {
                adj_node = adj[curr_node][i].first;
                dist = curr_dist + adj[curr_node][i].second;

                if(freq[adj_node] < k)  // optimization 2
                    pq.push({ dist, adj_node });
            }
        }

        sz = ans.size();
        for(i = 0; i < sz; ++i)
            cout << ans[i] << ' ';
        cout << '\n';

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