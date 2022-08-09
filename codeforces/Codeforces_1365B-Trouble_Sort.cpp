/**
 * Codeforces Round #648 (Div. 2)
 * Problem D - Trouble Sort
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

#define LIM 500

class Solution {
    int arr[LIM];
public:
    void solve()
    {
        int n, el, i;

        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> arr[i];

        int zero = 0, one = 0 ;
        for(i = 0; i < n; ++i)
        {
            cin >> el;

            if(!el) ++zero;
            else ++one;
        }

        if(is_sorted(arr, arr+n) || (zero && one))
            cout << "Yes\n";
        else cout << "No\n";

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