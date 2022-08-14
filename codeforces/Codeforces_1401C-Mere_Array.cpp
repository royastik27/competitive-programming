/**
 * Codeforces Round #665 (Div. 2)
 * Problem C - Mere Array
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:
    bool solve()
    {
        int n, el, i;
        vector <int> arr, sarr;

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> el;
            arr.push_back(el);
            sarr.push_back(el);
        }

        sort(sarr.begin(), sarr.end());

        for(i = 0; i < n; ++i)
        {
            if(arr[i] != sarr[i] && arr[i] % sarr[0])
                return false;
        }

        return true;
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
        if(sol.solve()) cout << "YES\n";
        else cout << "NO\n";
    
    return 0;
}