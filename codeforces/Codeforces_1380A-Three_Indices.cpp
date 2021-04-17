/**
* Educational Codeforces Round 91 (Rated for Div. 2)
* Problem A - Three Indices
* Time: 124 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 1000
#define INF 1001

typedef struct
{
    int data, position;
}Type;

Type MIN[LIMIT * 3];
int ara[LIMIT + 1], i, j;

void build_min(int b, int e, int node = 1)
{
    if(b == e)
    {
        MIN[node].data = ara[b];
        MIN[node].position = b;
        return;
    }

    int left, right, mid;

    left = node * 2;
    right = left + 1;

    mid = (b + e) / 2;

    build_min(b, mid, left);
    build_min(mid+1, e, right);

    if(MIN[left].data < MIN[right].data)
    {
        MIN[node].data = MIN[left].data;
        MIN[node].position = MIN[left].position;
    }
    else
    {
        MIN[node].data = MIN[right].data;
        MIN[node].position = MIN[right].position;
    }
}

Type query_min(int b, int e, int node = 1)
{
    if(b > j || e < i)
    {
        Type temp;
        temp.data = INF;
        temp.position = -1;
        return temp;
    }
    else if(b >= i && e <= j)
        return MIN[node];

    int left, right, mid;
    Type q1, q2;

    left = node * 2;
    right = left + 1;

    mid = (b + e) / 2;

    q1 = query_min(b, mid, left);
    q2 = query_min(mid+1, e, right);

    if(q1.data < q2.data)
        return q1;
    else
        return q2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC, len, ans1, ans2, ans3;
    Type q1, q2;
    register int k;

    cin >> TC;

    while(TC--)
    {
        cin >> len;

        for(k = 1; k <= len; ++k)
            cin >> ara[k];

        build_min(1, len);

        ans1 = -1;

        for(k = 2; k <= len - 1; ++k)
        {
            i = 1; j = k-1;
            q1 = query_min(1, len);
            i = k+1; j = len;
            q2 = query_min(1, len);

            if(ara[k] > q1.data && ara[k] > q2.data)
            {
                ans2 = k;
                ans1 = q1.position;
                ans3 = q2.position;
                break;
            }
        }

        if(ans1 == -1)
            cout << "NO\n";
        else
            cout << "YES\n" << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
    }

    return 0;
}
