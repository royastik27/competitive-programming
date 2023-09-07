/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;

#define LIM 110

class Solution
{
    int arr[LIM], tree[LIM*3];

    int query(int b, int e, int node = 1)
    {
        if(b > right || e < left)
            return 0;
        else if(b >= left && e <= right)
            return tree[node];
        else
        {
            int mid = (b+e) / 2, left = node*2, right = left + 1;

            return query(b, mid, left) ^ query(mid+1, e, right);
        }
    }

    void build(int b, int e, int node = 1)
    {
        if(b == e)
            tree[node] = arr[b];
        else
        {
            int mid = (b+e) / 2, left = node*2, right = left + 1;

            build(b, mid, left);
            build(mid+1, e, right);

            tree[node] = tree[left] ^ tree[right];
        }

        return;
    }
public:
    void solve()
    {
        int n;
        bool el;

        cin >> n;

        for(i = 1; i <= n; ++i)
            cin >> arr[i];

        ans0 = ans1 = 0;
        for(i = 1; i <= n; ++i)
        {
            cin >> el;

            if(el) ans1 ^= el;
            else ans0 ^= el;
        }

        build(1, n);

        cin >> q;

        while(q--)
        {
            cin >> op;

            if(op == 1)
            {
                cin >> left >> right;

                res = query(1, n);

                ans0 ^= res;
                ans1 ^= res;
            }
            else
            {
                cin >> el;

                if(el) cout << ans1 << '\n';
                else cout << ans0 << '\n';
            }
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