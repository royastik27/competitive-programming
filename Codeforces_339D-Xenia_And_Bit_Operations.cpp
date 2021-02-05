/**
* Codeforces Contest 339
* Problem D - Xenia and Bit Operations
* Time: 1652 ms
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

#define MAX 131073

/* All are 1 based indexed */

int ara[MAX], tree[MAX * 2], p, value;
bool toOR;

void buildTree(int node, int b, int e)
{
    // for leaf nodes
    if(b == e)
    {
        tree[node] = ara[b];
        toOR = true;
        return;
    }

    int left, right, mid;
    left = node * 2;
    right = left + 1;
    mid = (b + e) / 2;

    buildTree(left, b, mid);
    buildTree(right, mid+1, e);

    if(toOR)
    {
        tree[node] = tree[left] | tree[right];
        toOR = false;
    }
    else
    {
        tree[node] = tree[left] ^ tree[right];
        toOR = true;
    }
}

void update(int node, int b, int e)
{
    // for irrelevant nodes
    if(b > p || e < p)
        return;
    // for that leaf node
    else if(b == e && e == p)
    {
        tree[node] = value;
        toOR = true;
        return;
    }

    int left, right, mid;
    left = node * 2;
    right = left + 1;
    mid = (b + e) / 2;

    update(left, b, mid);
    update(right, mid+1, e);

    if(toOR)
    {
        tree[node] = tree[left] | tree[right];
        toOR = false;
    }
    else
    {
        tree[node] = tree[left] ^ tree[right];
        toOR = true;
    }
}

int main()
{
    int nElements, nQueries;

    cin >> nElements >> nQueries;

    nElements = pow(2, nElements);

    for(int i = 1; i <= nElements; ++i)
        cin >> ara[i];

    buildTree(1, 1, nElements);

    while(nQueries--)
    {
        cin >> p >> value;

        update(1, 1, nElements);
        cout << tree[1] << '\n';
    }

    return 0;
}
