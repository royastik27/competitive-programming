/**
 * Codeforces Round #333 (Div. 2)
 * Problem B - Approximating a Constant Range
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
        int n, i, j, prev, curr, ans, last_idx;
        vector <int> vec;

        cin >> n >> prev;

        vec.push_back(2);
        for(i = 1; i < n; ++i)
        {
            cin >> curr;
            
            vec.push_back(curr - prev);

            prev = curr;
        }

        ans = 0;
        for(i = 1, j = 1, last_idx = 0; j < n; ++j)
        {
            if(vec[j])
            {
                if(vec[j] == vec[last_idx])
                    i = last_idx + 1;

                last_idx = j;
            }
            
            ans = max(ans, j - i + 2);
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