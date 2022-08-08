/**
 * AtCoder Beginner Contest 258
 * Problem C - Rotation
 * TIME: 81 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution {
    
public:
    void solve()
    {
        int n, nQueries;
        string str;

        cin >> n >> nQueries >> str;

        int op, val, offset = 0, forw;
        while(nQueries--)
        {
            cin >> op >> val;

            if(op == 1) offset = (offset + val) % n;
            else
            {
                forw = n - offset;

                cout << str[ (val - 1 + forw) % n ] << '\n';
            }
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    sol.solve();
    
    return 0;
}