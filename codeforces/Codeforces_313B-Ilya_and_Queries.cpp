/**
* Codeforces Round #186 (Div. 2)
* Porblem B - Ilya and Queries
* Time: 654 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIMIT 100000

// tree is one based indexed
char str[LIMIT + 1];
int tree[LIMIT * 3], i, j;

void build(int b, int e, int node)
{
    if(b + 1 == e)
    {
        if(str[b] == str[e])
            tree[node] = 1;
        else tree[node] = 0;

        return;
    }

    int left, right, mid;
    left = node * 2;
    right = left + 1;
    mid = (b + e) / 2;

    build(b, mid, left);
    build(mid, e, right);

    tree[node] = tree[left] + tree[right];
}

int query(int b, int e, int node)
{
    if(b >= i && e <= j)
        return tree[node];
    else if(b > j || e < i || b+1 == e)
        return 0;


    int left, right, mid;
    left = node * 2;
    right = left + 1;
    mid = (b + e) / 2;

    return query(b, mid, left) + query(mid, e, right);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int len, nQueries;

    cin >> str;
    len = strlen(str);

    build(0, len-1, 1);

    cin >> nQueries;
    while(nQueries--)
    {
        cin >> i >> j;
        --i; --j;
        cout << query(0, len-1, 1) << '\n';
    }

    return 0;
}
