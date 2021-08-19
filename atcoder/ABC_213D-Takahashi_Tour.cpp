/**
 * AtCoder Beginner Contest 213
 * Problem D - Takahashi Tour
 * Time: 169 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <queue>

using namespace std;

#define LIM 200001
priority_queue <int, vector<int>, greater<int>> adj[LIM]; // min heap
bool visited[LIM];

void visit(int i)
{
    cout << i << ' ';
    visited[i] = true;

    while(adj[i].size()) {
        if(visited[adj[i].top()]) adj[i].pop();
        else {
            visit(adj[i].top());
            cout << i << ' ';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, u, v;

    cin >> n;

    while(--n) {
        cin >> u >> v;
        adj[u].push(v);
        adj[v].push(u);
    }

    visit(1);

    cout << '\n';

    return 0;
}
