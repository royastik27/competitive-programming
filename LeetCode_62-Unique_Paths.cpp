/**
* LeetCode 62 - Unique Paths
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
* Memory Usage: 5.9 MB, less than 85.71% of C++ online submissions for Unique Paths.
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
    int m, n, mem[101][101];
public:
    int solve(int x, int y)
    {
        if(y > n || x > m)
            return 0;
        else if(mem[x][y] != -1)
            return mem[x][y];
        else if(x == m && y == n)
            return 1;
        else
            return mem[x][y] = solve(x, y+1) + solve(x+1, y);
    }

    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;

        memset(mem, -1, sizeof(mem));

        return solve(1, 1);
    }
};

int main()
{
    Solution solve;

    cout << solve.uniquePaths(7, 3) << '\n';

    return 0;
}
