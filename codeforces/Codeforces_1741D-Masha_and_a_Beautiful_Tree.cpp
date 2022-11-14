/**
 * Codeforces Round #826 (Div. 3)
 * Problem D - Masha and a Beautiful Tree
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 262144

class Solution{
    int perm[LIM], cnt;

    pair <int, int> op(int beg, int end)
    {
        // first = min, second = max

        if(beg == end)
            return { perm[beg], perm[beg] };
        
        int mid = (beg+end) / 2;

        pair <int, int> res1 = op(beg, mid);
        pair <int, int> res2 = op(mid+1, end);

        if(res1.first == res2.second + 1)
        {
            ++cnt;
            return { res2.first, res1.second };
        }
        
        if(res2.first == res1.second + 1)
            return { res1.first, res2.second };

        return { 0, 0 };
    }
public:
    int solve()
    {
        int m, i;

        cin >> m;
        for(i = 0; i < m; ++i) cin >> perm[i];

        cnt = 0;
        pair <int, int> res = op(0, m-1);

        return res.first ? cnt : -1;
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
        cout << sol.solve() << '\n';

    return 0;
}