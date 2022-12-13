/**
 * Codeforces Round #648 (Div. 2)
 * Problem C - Rotation Matching
 * TIME: 109 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 200000
 
class Solution
{
    int posA[LIM+1], posB[LIM+1], freq[LIM], n, mx;
public:
    int solve()
    {
        int i, num, diff;

        cin >> n;

        for(i = 1; i <= n; ++i)
        {
            cin >> num;
            posA[num] = i;
        }
        for(i = 1; i <= n; ++i)
        {
            cin >> num;
            posB[num] = i;
        }

        memset(freq, 0, n*sizeof(int));
        mx = 0;
        for(i = 1; i <= n; ++i)
        {
            diff = posA[i] - posB[i];

            if(diff < 0)
                diff += n;
            
            if(++freq[diff] > mx)
                mx = freq[diff];
        }

        return mx;
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