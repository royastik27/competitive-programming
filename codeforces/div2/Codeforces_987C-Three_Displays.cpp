/**
 * Codeforces Round #485 (Div. 2)
 * Problem C - Three displays
 * TIME: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;
 
class Solution
{

public:
    int solve()
    {
        int n, el, i, j, ans = INT_MAX, left, right;
        vector <int> size, height;

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> el;
            size.push_back(el);
        }

        for(i = 0; i < n; ++i)
        {
            cin >> el;
            height.push_back(el);
        }

        for(i = 1; i < n-1; ++i)
        {
            left = INT_MAX;
            for(j = 0; j < i; ++j)
            {
                if(size[j] < size[i])
                    left = min(left, height[j]);
            }

            right = INT_MAX;
            for(j = i+1; j < n; ++j)
            {
                if(size[j] > size[i])
                    right = min(right, height[j]);
            }

            if(left == INT_MAX || right == INT_MAX)
                continue;

            ans = min(ans, left + height[i] + right);
        }        
 
        return ans == INT_MAX ? -1 : ans;
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