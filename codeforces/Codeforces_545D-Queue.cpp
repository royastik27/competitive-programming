/**
 * Codeforces Round #303 (Div. 2)
 * Problem D - Queue
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:
    int solve()
    {
        int ans = 1, n, i, el;
        vector <int> arr;
        vector <int>::iterator it, it2;

        cin >> n;
        for(i = 0; i < n; ++i)
        {
            cin >> el;
            arr.push_back(el);
        }

        sort(arr.begin(), arr.end());
        
        long long int pre = arr[0];

        for(i = 1; i < n; ++i)
        {
            it = lower_bound(arr.begin(), arr.end(), pre);

            if(it == arr.end()) break;
            else if(it == arr.begin()) ++it;

            ++ans;
            pre += *it;
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    cout << sol.solve() << '\n';
    
    return 0;
}