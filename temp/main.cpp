/**
 * Codeforces Round #672 (Div. 2)
 * Problem C1 - Pokémon Army (easy version)
 * Time: 78 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 300001

class Solution
{
    int arr[LIM];

    public:
    long long int solve()
    {
        long long int ans = 0;
        int n, nQueries, i, add, mn;

        cin >> n >> nQueries;

        for(i = 0; i < n; ++i) cin >> arr[i];

        mn = 0; add = arr[0];

        for(i = 1; i < n; ++i)
        {
            if(arr[i] < arr[i-1])
            {
                ans += add;
                mn = arr[i];
                add = 0;
            }
            else
                add = arr[i] - mn;
        }

        ans += add;
        
        return ans;
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