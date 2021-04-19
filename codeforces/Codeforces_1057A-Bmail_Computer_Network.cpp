/**
* Mail.Ru Cup 2018 - Practice Round
* Problem A - Bmail Computer Network
* Time: 186 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <stack>

#define LIMIT 200001

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int nRoutes, routes[LIMIT], i;

    cin >> nRoutes;

    for(i = 2; i <= nRoutes; ++i)
        cin >> routes[i];

    stack <int> path;

    path.push(nRoutes);

    while(path.top() != 1)
        path.push(routes[path.top()]);

    while(!path.empty())
    {
        cout << path.top() << ' ';
        path.pop();
    }

    cout << '\n';

    return 0;
}
