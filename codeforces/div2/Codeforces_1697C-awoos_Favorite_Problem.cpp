/**
 * Educational Codeforces Round 130 (Rated for Div. 2)
 * Problem C - awoo's Favorite Problem
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <queue>

using namespace std;

#define A 0
#define B 1
#define C 2

class Solution
{
    priority_queue < int, vector <int> , greater <int> > que[3];
    int n, i;
    string str, pat;
public:
    bool solve()
    {
        cin >> n >> str >> pat;

        que[A].push(n);
        que[B].push(n);
        que[C].push(n);

        for(i = n-1; i >= 0; --i)
            que[int(str[i] - 'a')].push(i);

        for(i = 0; i < n; ++i)
        {
            if(str[i] == pat[i])
            {
                que[int(str[i]-'a')].pop();
                continue;
            }

            if(str[i] == 'a' && pat[i] == 'b' && que[B].top() < que[C].top())
            {
                que[A].push(que[B].top());
                str[que[B].top()] = 'a';

                que[B].pop();
                que[A].pop();
            }
            else if(str[i] == 'b' && pat[i] == 'c' && que[C].top() < que[A].top())
            {
                que[B].push(que[C].top());
                str[que[C].top()] = 'b';

                que[C].pop();
                que[B].pop();
            }
            else break;
        }

        while(que[A].size()) que[A].pop();
        while(que[B].size()) que[B].pop();
        while(que[C].size()) que[C].pop();

        return i == n;
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
        cout << (sol.solve() ? "YES\n" : "NO\n");
    
    return 0;
}