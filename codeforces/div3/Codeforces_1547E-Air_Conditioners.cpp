/**
* Codeforces Round 731 (Div. 3)
* Problem E - Air Conditioners
* TIME: 248 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

typedef struct {
    int pos, temp;
}Conditioner;

#define INF 1000300000

bool cmp(Conditioner a, Conditioner b) { return a.pos < b.pos; }

class Solution
{
    vector <Conditioner> con;
    vector <int> forw, back;
public:
    void solve()
    {
        int n, k, i, j;

        cin >> n >> k;

        con.resize(k);
        forw.resize(n+1);
        back.resize(n+2);

        for(i = 0; i < k; ++i)
            cin >> con[i].pos;

        for(i = 0; i < k; ++i)
            cin >> con[i].temp;

        // processing
        sort(con.begin(), con.end(), cmp);

        // forward min
        forw[0] = INF;
        for(i = 1, j = 0; i <= n; ++i) {
            if(j == k || i < con[j].pos)
                forw[i] = forw[i-1] + 1;
            else {
                forw[i] = min(con[j].temp, forw[i-1]+1);
                ++j;
            }
        }

        // backward min
        back[n+1] = INF;
        for(i = n, j = k-1; i >= 1; --i) {
            if(j < 0 || i > con[j].pos)
                back[i] = back[i+1] + 1;
            else {
                back[i] = min(con[j].temp, back[i+1]+1);
                --j;
            }
        }

        // answer
        for(i = 1; i <= n; ++i)
            cout << min(forw[i], back[i]) << ' ';
        cout << '\n';
        
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