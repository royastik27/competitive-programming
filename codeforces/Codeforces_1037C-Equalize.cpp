/**
 * Manthan, Codefest 18 (rated, Div. 1 + Div. 2)
 * Problem C - Equalize
 * Time: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 1000002

class Solution
{
    char a[LIM], b[LIM];
    public:
    int solve()
    {
        int n, cost = 0;

        cin >> n >> a >> b;
        a[n] = b[n] = '0';

        for(int i = 0; i < n; ++i)
        {
            if(a[i] != b[i])
            {
                if(a[i] == b[i+1] && a[i+1] == b[i])
                    ++i;

                ++cost;
            }
        }

        return cost;
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