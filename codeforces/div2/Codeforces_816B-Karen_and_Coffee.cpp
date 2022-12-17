/**
 * Codeforces Round #419 (Div. 2)
 * Problem B - Karen and Coffee
 * TIME: 264 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 200000

class Solution
{
    int n, k, q, pre[LIM+2], tree[LIM * 3], i, j;

    void build(int beg = 1, int end = LIM, int node = 1)
    {
        if(beg == end)
        {
            tree[node] = pre[beg] >= k ? 1 : 0;
            return;
        }

        int mid = (beg+end) / 2, left = node * 2;

        build(beg, mid, left);
        build(mid+1, end, left + 1);

        tree[node] = tree[left] + tree[left+1];

        return;
    }

    int query(int beg = 1, int end = LIM, int node = 1)
    {
        if(beg > j || end < i)
            return 0;
        else if(beg >= i && end <= j)
            return tree[node];

        int mid = (beg+end) / 2, left = node * 2;

        return query(beg, mid, left) + query(mid+1, end, left + 1);
    }
public:
    void solve()
    {
        cin >> n >> k >> q;

        memset(pre, 0, sizeof(pre));

        while(n--)
        {
            cin >> i >> j;

            ++pre[i];
            --pre[j+1];
        }

        for(i = 2; i <= LIM; ++i)
            pre[i] += pre[i-1];

        build();

        while(q--)
        {
            cin >> i >> j;

            cout << query() << '\n';
        }        

        return;
    }
};

class Solution2
{
    int n, k, q, freq[LIM+2], i, j;
public:
    void solve()
    {
        cin >> n >> k >> q;

        memset(freq, 0, sizeof(freq));

        while(n--)
        {
            cin >> i >> j;

            ++freq[i];
            --freq[j+1];
        }

        for(i = 1; i <= LIM; ++i)
        {
            // passing value towards
            freq[i+1] += freq[i];

            // processing value
            freq[i] = freq[i] >= k ? 1 : 0;

            // prefix sum
            freq[i] += freq[i-1];
        }

        while(q--)
        {
            cin >> i >> j;

            cout << (freq[j] - freq[i-1]) << '\n';
        }

        return;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution2 sol;
    
    sol.solve();
    
    return 0;
}