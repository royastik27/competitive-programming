/**
 * Educational Codeforces Round 136 (Rated for Div. 2)
 * Problem B - Array Recovery
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 100

class Solution {
    int arr[LIM];
public:
    void solve()
    {
        int i, n;
        bool isPossible;

        cin >> n;

        for(i = 0; i < n; ++i) cin >> arr[i];

        --n;
        isPossible = true;
        for(i = 0; i < n; ++i)
            if(arr[i] < arr[i+1] || arr[i+1] == 0)
                arr[i+1] = arr[i]+arr[i+1];
            else isPossible = false;

        if(isPossible)
        {
            ++n;
            for(i = 0; i < n; ++i)
                cout << arr[i] << ' ';
            cout << '\n';
        } else cout << "-1\n";  
        
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