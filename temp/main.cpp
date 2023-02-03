/**
 * Codeforces Beta Round #80 (Div. 1 Only)
 * Problem B - Cthulhu
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <set>

using namespace std;

// #define LIM 200001
#define LIM 2001

class Solution
{
    int n, q, i, j, arr[LIM];
    bool tree[3 * LIM];

    int get_length(int n)
    {
        int len = 0;

        while(n)
        {
            ++len;
            n /= 10;
        }

        return len;
    }

    void build(int b, int e, int node = 1)
    {
        if(b == e)
        {
            tree[node] = (get_digit(arr[b]) == 1);
            return;
        }

        int mid = (b+e) / 2, left = node*2, right = left + 1;

        build(b, mid, left);
        build(mid+1, e, right);

        tree[node] = tree[left] & tree[right];

        return;
    }

    void update(int b, int e, int node = 1)
    {
        if(tree[node]) // optimization
            return;

        if(b == e)
        {
            arr[b] = get_digit(arr[b]);
            tree[node] = (arr[b] == 1);

            return;
        }
        else if(b > j || e < i)
            return;

        int mid = (b+e)/2, left = node*2, right = left+1;

        update(b, mid, left);
        update(mid+1, e, right);

        tree[node] = tree[left] & tree[right];

        return;
    }
public:
    void solve()
    {
        cin >> n >> q;

        for(i = 1; i <= n; ++i)
            cin >> arr[i];

        build(1, n);

        while(q--)
        {
            cin >> op >> i;

            if(op == 1)
            {
                cin >> j;

                update(1, n);
            }
            else cout << arr[i] << '\n';
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        sol.solve();
 
    return 0;
}