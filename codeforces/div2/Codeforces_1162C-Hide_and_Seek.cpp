/**
 * Codeforces Round #557 (Div. 2) [based on Forethought Future Cup - Final Round]
 * Problem C - Hide and Seek
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 100000

class Solution
{
    int n, q, first_pos[LIM+1], last_pos[LIM+2], num, ans;
public:
    int solve()
    {
        int i;

        cin >> n >> q;

        memset(last_pos, -1, (n+1)*sizeof(int));
        last_pos[0] = LIM;
        last_pos[n+1] = LIM;

        for(i = 0; i < q; ++i)
        {
            cin >> num;

            if(last_pos[num] == -1)
                first_pos[num] = i;
            
            last_pos[num] = i;
        }

        ans = 0;
        for(i = 1; i <= n; ++i)
        {
            if(last_pos[i] == -1)
            {
                if(i == 1 || i == n)
                    ans += 2;
                else
                    ans += 3;

            }
            else
            {
                if(last_pos[i+1] < first_pos[i])
                    ++ans;

                if(last_pos[i-1] < first_pos[i])
                    ++ans;
            }
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