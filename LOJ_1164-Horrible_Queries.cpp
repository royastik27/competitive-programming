/**
* LightOJ 1164 - Horrible Queries
* Time: 675 ms
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

#define MAX 100000

/* tree is 1 based indexed */
/* Queries are 0 based indexed */

struct Type
{
    long long int sum, prop;
}tree[MAX * 3];

int i, j;
long long int value;

void add(int node, int b, int e)
{
    // for irrelevant nodes
    if(b > j || e < i)
        return;
    // for relevant nodes
    else if(b >= i && e <= j)
    {
        tree[node].sum += (e - b + 1) * value;
        tree[node].prop += value;
    }
    else
    {
        int left, right, mid;
        left = node * 2;
        right = left + 1;
        mid = (b + e) / 2;

        add(left, b, mid);
        add(right, mid+1, e);

        tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
    }
}

long long int query(int node, int b, int e, long long int carry = 0)
{
    // for irrelevant nodes
    if(b > j || e < i)
        return 0;
    // for relevant nodes
    else if(b >= i && e <= j)
        return tree[node].sum + (e - b + 1) * carry;

    int left, right, mid;
    left = node * 2;
    right = left + 1;
    mid = (b + e) / 2;

    return query(left, b, mid, carry + tree[node].prop) + query(right, mid+1, e, carry + tree[node].prop);
}

int main()
{
    int TC, nElements, nQueries, option, k;

    cin >> TC;

    for(k = 1; k <= TC; ++k)
    {
        cin >> nElements >> nQueries;

        cout << "Case " << k << ":\n";

        while(nQueries--)
        {
            cin >> option >> i >> j;

            if(option == 0)
            {
                cin >> value;
                add(1, 0, nElements-1);
            }
            else
                cout << query(1, 0, nElements-1) << '\n';
        }

        if(TC)
        {
            // initializing segment tree
            nElements *= 3;
            for(i = 1; i <= nElements; ++i)
                tree[i].sum = tree[i].prop = 0;
        }
    }

    return 0;
}
