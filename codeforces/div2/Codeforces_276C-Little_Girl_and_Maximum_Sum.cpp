/**
 * Codeforces Round #169 (Div. 2)
 * Problem C - Little Girl and Maximum Sum
 * TIME: 264 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

class Solution
{
    vector <int> tree, freq;
    int left, right;

    void update(int beg, int end, int node = 1)
    {
        if(beg > right || end < left)
            return;
        else if(beg >= left && end <= right)
            ++tree[node];
        else
        {
            int left = node*2, mid = (beg+end) / 2;

            update(beg, mid, left);
            update(mid+1, end, left+1);
        }

        return;
    }

    void updateFreq(int beg, int end, int node = 1, int cum = 0)
    {
        if(beg == end)
        {
            freq.push_back(tree[node] + cum);
            return;
        }

        int left = node*2, mid = (beg+end) / 2;

        cum += tree[node];

        updateFreq(beg, mid, left, cum);
        updateFreq(mid+1, end, left+1, cum);

        return;
    }
public:
    ll solve()
    {
        int n, q, i, j;
        vector <int> vec;
        ll sum = 0;

        cin >> n >> q;

        tree = vector <int>(4*n, 0);

        for(i = 0; i < n; ++i)
        {
            cin >> j;
            vec.push_back(j);
        }

        while(q--)
        {
            cin >> left >> right;
            update(1, n);
        }

        updateFreq(1, n);
        sort(freq.begin(), freq.end());
        sort(vec.begin(), vec.end());

        for(i = 0; i < n; ++i)
            sum += ll(vec[i]) * freq[i];

        return sum;
    }
};

class Solution2
{

public:
    ll solve()
    {
        int n, q, i, j;
        ll ans = 0;

        cin >> n >> q;
        vector <int> vec, pre(n+1, 0);

        for(i = 0; i < n; ++i)
        {
            cin >> j;
            vec.push_back(j);
        }

        while(q--)
        {
            cin >> i >> j;

            ++pre[--i];
            --pre[j];
        }

        for(i = 1; i < n; ++i)
            pre[i] += pre[i-1];

        sort(pre.begin(), pre.end());
        sort(vec.begin(), vec.end());

        for(i = 0; i < n; ++i)
            ans += ll(vec[i])*pre[i];

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol2;

    cout << sol2.solve() << '\n';

    return 0;
}