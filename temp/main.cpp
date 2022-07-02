/**
 * 2020 ICPC, COMPFEST 12, Indonesia Multi-Provincial Contest (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
 * Problem F - Flamingoes of Mystery
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution
{
    public:
    void solve(int n)
    {
        int ans, arr[n], start, end, mid, i, nQueries, x, y, ub, lb;

        cin >> nQueries;

        for(i = 0; i < n; ++i)
            cin >> arr[i];

        while(nQueries--)
        {
            cin >> x >> y;

            start = 0; end = n - 1;
            while(start <= end)
            {
                mid = (start + end) / 2;
                if(x > arr[mid])
                    start = mid + 1;
                else end = mid - 1;
            }
            lb = start;

            start = 0; end = n - 1;
            while(start <= end)
            {
                mid = (start + end) / 2;
                if(y < arr[mid])
                    end = mid - 1;
                else start = mid + 1;
            }

            ub = start;

            cout << ub - lb << '\n';
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    int TC, n, k = 0;

    cin >> TC;

    while(TC--)
    {
        cout << "Case " << ++k << ":\n";
        cin >> n;
        sol.solve(n);
    }
    
    return 0;
}