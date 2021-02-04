/**
* LightOJ 1082 - Array Queries
* Time: 656 ms
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

#define MAX 100000
#define INF 100001

int tree[MAX * 3], ara[MAX + 1], i, j;

void init(int node, int b, int e)
{
    // for leaf nodes
    if(b == e)
        tree[node] = ara[b];
    else
    {
        int left, right, mid;
        left = node * 2;
        right = left + 1;
        mid = (b + e) / 2;

        init(left, b, mid);
        init(right, mid+1, e);

        tree[node] = (tree[left] <= tree[right]) ? tree[left] : tree[right];
    }
}

int query(int node, int b, int e)
{
    // for irrelevant nodes
    if(b > j || e < i)
        return INF;
    // for relevant nodes
    else if(b >= i && e <= j)
        return tree[node];

    int left, right, mid, q1, q2;
    left = node * 2;
    right = left + 1;
    mid = (b + e) / 2;

    q1 = query(left, b, mid);
    q2 = query(right, mid+1, e);

    return (q1 <= q2) ? q1 : q2;
}

int main()
{
    int TC, k, no_elements, no_queries, i;

    cin >> TC;

    for(k = 1; k <= TC; ++k)
    {
        cin >> no_elements >> no_queries;

        // getting input
        for(i = 1; i <= no_elements; ++i)
            cin >> ara[i];

        // initializing segment tree
        init(1, 1, no_elements);

        cout << "Case " << k << ":\n";
        while(no_queries--)
        {
            // getting the value of global i and j
            cin >> ::i >> ::j;

            cout << query(1, 1, no_elements) << '\n';
        }
    }

    return 0;
}
