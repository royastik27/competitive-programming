/**
* Codeforces Problem 52C - Circular RMQ
* Time: 1201 ms
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define MAX 200000
#define INF 1000001

/* tree is 1 based indexed */
/* ara is 0 based indexed */

struct Type
{
    long long int value, prop;
}tree[MAX * 3];

int ara[MAX], leftIndex, rightIndex, value;
const long long int Inf = 200001000001;

void buildTree(int node, int b, int e)
{
    // for leaf nodes
    if(b == e)
    {
        tree[node].value = ara[b];
        tree[node].prop = 0;
        return;
    }

    int left, right, mid;
    left = node * 2;
    right = left + 1;
    mid = (b + e) / 2;

    buildTree(left, b, mid);
    buildTree(right, mid+1, e);

    tree[node].value = min(tree[left].value, tree[right].value);
    tree[node].prop = 0;
}

void update(int node, int b, int e)
{
    // for irrelevant nodes (including leaf nodes)
    if(b > rightIndex || e < leftIndex)
        return;
    // for relevant nodes
    else if(b >= leftIndex && e <= rightIndex)
    {
        tree[node].value += value;
        tree[node].prop += value;
    }
    else
    {
        int left, right, mid;
        left = node * 2;
        right = left + 1;
        mid = (b + e) / 2;

        update(left, b, mid);
        update(right, mid+1, e);

        tree[node].value = min(tree[left].value, tree[right].value) + tree[node].prop;
    }
}

long long int query(int node, int b, int e, long long int carry = 0)
{
    // for irrevalent queries
    if(b > rightIndex || e < leftIndex)
        return Inf;
    // for relevant nodes
    if(b >= leftIndex && e <= rightIndex)
        return tree[node].value + carry;

    int left, right, mid;
    left = node * 2;
    right = left + 1;
    mid = (b + e) / 2;

    return min(query(left, b, mid, carry + tree[node].prop), query(right, mid+1, e, carry + tree[node].prop));
}

int main()
{
    int nElements, nOperations, lastIndex, temp, q1, q2;
    char input[22], * token;
    // Max Input: 199999 199999 -100000; SIZE: 22

    cin >> nElements;

    // getting input
    for(leftIndex = 0; leftIndex < nElements; ++leftIndex)
        cin >> ara[leftIndex];

    lastIndex = nElements - 1;

    // building segment tree
    buildTree(1, 0, lastIndex);

    cin >> nOperations;
    cin.ignore();

    while(nOperations--)
    {
        cin.getline(input, 22);

        // parsing input
        token = strtok(input, " ");
        leftIndex = atoi(token);

        token = strtok(NULL, " ");
        rightIndex = atoi(token);

        token = strtok(NULL, " ");
        if(token != NULL)
            value = atoi(token);
        else value = INF;

        // if value is not INF, then value exists
        if(value == INF)
        {
            if(leftIndex > rightIndex)
            {
                temp = rightIndex;
                rightIndex = nElements-1;
                q1 = query(1, 0, lastIndex);

                leftIndex = 0;
                rightIndex = temp;
                q2 = query(1, 0, lastIndex);

                cout << min(q1, q2) << '\n';
            }
            else
                cout << query(1, 0, lastIndex) << '\n';
        }
        else
        {
            if(leftIndex > rightIndex)
            {
                temp = rightIndex;
                rightIndex = nElements-1;
                update(1, 0, lastIndex);

                leftIndex = 0;
                rightIndex = temp;
                update(1, 0, lastIndex);
            }
            else
                update(1, 0, lastIndex);
        }
    }

    return 0;
}
