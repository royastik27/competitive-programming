/**
 * Codeforces Round #298 (Div. 2)
 * Problem B - Covered Path
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution
{

public:
    int solve()
    {
        int v1, v2, time, d, sum, v, i, j;

        cin >> v1 >> v2 >> time >> d;

        sum = v1 + v2;
        v = v1;
        
        for(i = 2; i < time; ++i)
        {
            for(j = v+d; j >= v-d; --j)
            {
                if(max(v2 - j, j - v2) > (time-i)*d)
                    continue;
                else
                {
                    sum += v = j;
                    break;
                }
            }
        }

        return sum;
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