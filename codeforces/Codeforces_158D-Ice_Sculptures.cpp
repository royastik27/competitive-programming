/**
 * VK Cup 2012 Qualification Round 1
 * Problem D - Ice Sculptures
 * TIME: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution{
    vector <int> vec;
    int n;

    int get_sum(int param)
    {
        if(n / param < 3)
            return INT_MIN;

        int i, j, sum, mx = INT_MIN;

        for(i = 0; i < param; ++i)
        {
            sum = vec[i];

            j = (i + param) % n;

            while(j != i)
            {
                sum += vec[j];
                j = (j + param) % n;
            }

            mx = max(mx, sum);
        }

        return mx;
    }
public:
    int solve()
    {
        int i, el, ans, root;

        cin >> n;

        ans = 0;
        for(i = 0; i < n; ++i) { cin >> el; vec.push_back(el); ans += el; }

        root = sqrt(n);

        for(i = 2; i <= root; ++i)
        {
            if(n % i == 0)
                ans = max(ans, max(get_sum(i), get_sum(n/i)));
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