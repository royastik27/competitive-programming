/**
* UVA 762 - We Ship Cheap
* Time: 40 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

map <string, bool> visited;
map <string, vector<string>>adj;

void shortest_path(string city1, string city2)
{
    queue <string> que;
    map <string, string> prev;

    vector <string> curr;
    string currCity;
    int i, Size;

    // BFS
    que.push(city1);
    visited[city1] = true;

    while(!que.empty())
    {
        currCity = que.front();
        curr = adj[currCity];
        Size = curr.size();

        que.pop();

        for(i = 0; i < Size; ++i)
        {
            if(!visited[curr[i]]){
                que.push(curr[i]);
                visited[curr[i]] = true;
                prev[curr[i]] = currCity;
            }
        }
    }

    // getting the path
    if(prev.find(city2) == prev.end())
        cout << "No route\n";
    else
    {
        stack <string> path;

        path.push(city2);

        currCity = prev[city2];

        while(currCity != city1)
        {
            path.push(currCity);

            currCity = prev[currCity];
        }
        path.push(city1);

        // printing the result
        while(path.size() > 1)
        {
            cout << path.top() << ' ';
            path.pop();
            cout << path.top() << '\n';
        }
    }
}

int main()
{
    int links, TC = -1;
    string city1, city2;
    vector <string> temp;

    while(cin >> links)
    {
        while(links--)
        {
            cin >> city1 >> city2;

            temp.clear();
            temp.push_back(city2);

            if(adj.insert(make_pair(city1, temp)).second == false)
               adj[city1].push_back(city2);

            temp.clear();
            temp.push_back(city1);

            if(adj.insert(make_pair(city2, temp)).second == false)
                adj[city2].push_back(city1);


            visited.insert(make_pair(city1, false));
            visited.insert(make_pair(city2, false));
        }

        cin >> city1 >> city2;

        if(++TC) cout << '\n';
        shortest_path(city1, city2);

        adj.erase(adj.begin(), adj.end());
        visited.erase(visited.begin(), visited.end());
    }

    return 0;
}
