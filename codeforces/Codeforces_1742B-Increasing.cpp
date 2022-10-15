/**
 * Codeforces Round #827 (Div. 4)
 * Problem B - Increasing
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define LIM 100
 
class Solution {
    int arr[LIM];
public:
    bool solve()
    {
        int n, i;
 
        cin >> n;
 
        for(i = 0; i < n; ++i) cin >> arr[i];
 
        sort(arr, arr+n);
 
        for(i = 1; i < n; ++i)
            if(arr[i] == arr[i-1]) return false;
        
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