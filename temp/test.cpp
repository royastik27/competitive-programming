/**
 * Codeforces Round #479 (Div. 3)
 * Problem E - Cyclic Components
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <queue>

using namespace std;

typedef long long int ll;

class Solution
{
    int mx;
public:
    void fuck()
    {
        mx = 10;

        return;
    }
    void solve()
    {
        priority_queue <int> que;

        que.push(10);
        que.push(2);
        que.push(5);

        cout << que.size()

        // while(!que.empty())
        // {
        //     cout << que.top() << '\n';
        //     que.pop();
        // }

        

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