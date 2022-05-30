/**
 * LeetCode 851 - Loud and Rich
 * Time: 294 ms
 * AUTHOR: Astik Roy
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define DBG cout << "Line " << __LINE__ << ": Hey!\n"

class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int n = quiet.size(), i, curr, child;
        vector<int> answer(n);
        vector<int> adj[n];
        vector<bool> in(n), visited(n);
        queue<int> que;

        // ADJACANCY MATRIX
        for (i = 0; i < richer.size(); ++i)
        {
            adj[richer[i][0]].push_back(richer[i][1]);

            // CHECKING INDEGREE OF EACH NODE
            in[richer[i][1]] = true;
        }

        // INITIALIZING DEFAULT ANSWER
        for (i = 0; i < n; ++i)
            answer[i] = i;

        // PUSHING NODES WITH INDEGREE ZERO
        for (i = 0; i < n; ++i)
        {
            if (!in[i])
                que.push(i);
        }

        // BFS
        while (!que.empty())
        {
            curr = que.front();
            visited[curr] = true;
            que.pop();

            for (i = 0; i < adj[curr].size(); ++i)
            {
                child = adj[curr][i];

                if (quiet[answer[curr]] < quiet[answer[child]])
                {
                    answer[child] = answer[curr];
                    que.push(child);
                }

                if (!visited[child])
                    que.push(child);
            }
        }

        return answer;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> richer = {};
    vector<int> quiet = {0};

    vector<int> ans = obj.loudAndRich(richer, quiet);

    cout << "Answer:\n";
    for (auto it = ans.begin(); it != ans.end(); ++it)
        cout << *it << ' ';
    cout << '\n';

    return 0;
}
