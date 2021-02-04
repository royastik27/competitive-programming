/**
* LightOJ 1112 - Curious Robin Hood
* Time: 471 ms
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

#define MAX 100000

/* Sack is 0 based indexed */

int sack[MAX], tree[MAX * 3], i, j;

void init(int node, int b, int e)
{
    // for leaf nodes
    if(b == e)
        tree[node] = sack[b];
    else
    {
        int left, right, mid;
        left = node * 2;
        right = left + 1;
        mid = (b + e) / 2;

        init(left, b, mid);
        init(right, mid+1, e);

        tree[node] = tree[left] + tree[right];
    }
}

void addMoney(int node, int b, int e)
{
    // for irrelevant nodes
    if(b > i || e < i)
        return;
    else if(b == e)
    {
        tree[node] += j; // here j = money
        return;
    }

    int left, right, mid;
    left = node * 2;
    right = left + 1;
    mid = (b + e) / 2;

    addMoney(left, b, mid);
    addMoney(right, mid+1, e);

    tree[node] = tree[left] + tree[right];
}

void giveMoney(int node, int b, int e)
{
    // for irrelevant nodes
    if(b > i || e < i)
        return;
    else if(b == e)
    {
        cout << tree[node] << '\n';
        tree[node] = 0;
        return;
    }

    int left, right, mid;
    left = node * 2;
    right = left + 1;
    mid = (b + e) / 2;

    giveMoney(left, b, mid);
    giveMoney(right, mid+1, e);

    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e)
{
    // for irrelevant nodes
    if(b > j || e < i)
        return 0;
    // for relevant nodes
    else if(b >= i && e <= j)
        return tree[node];

    int left, right, mid;
    left = node * 2;
    right = left + 1;
    mid = (b + e) / 2;

    return query(left, b, mid) + query(right, mid+1, e);
}

int main()
{
    int TC, nSacks, nQueries, option, k;

    cin >> TC;

    for(k = 1; k <= TC; ++k)
    {
        cin >> nSacks >> nQueries;

        for(i = 0; i < nSacks; ++i)
            cin >> sack[i];

        // initializing segment tree
        init(1, 0, nSacks-1);

        cout << "Case " << k << ":\n";

        while(nQueries--)
        {
            cin >> option;

            switch(option)
            {
            case 1:
                // give all money and print the previous amount
                cin >> i;   // i = node
                giveMoney(1, 0, nSacks-1);
                break;
            case 2:
                // add money
                cin >> i >> j;      // i = node :: j = money
                addMoney(1, 0, nSacks-1);
                break;
            case 3:
                // find the total amount in the range i and j
                cin >> i >> j;
                cout << query(1, 0, nSacks-1) << '\n';
                break;
            }
        }
    }

    return 0;
}
