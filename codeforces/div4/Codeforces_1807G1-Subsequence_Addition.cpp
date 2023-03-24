/**
* Codeforces Round 859 (Div. 4)
* Problem G1 - Subsequence Addition (Easy Version)
* TIME: 46 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int ll;

#define LIM 5000

class Solution
{
    int arr[LIM], n;
    bool mem[LIM][LIM+1];
public:
    bool solve()
    {
        int i, j, mx, curr;

        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> arr[i];

        if(n == 1)
            return (arr[0] == 1);

        sort(arr, arr+n);
        mx = arr[n-1];
        memset(mem, 0, n*(LIM+1));

        // Dynamic Programming
        mem[0][0] = mem[0][1] = true;
        for(i = 2; i <= mx; ++i)
            mem[0][i] = false;
            
        for(i = 1; i+1 < n; ++i)
        {
            curr = arr[i];

            if(!mem[i-1][curr])
                return false;

            for(j = 0; j < curr; ++j)
                mem[i][j] = mem[i-1][j];

            for(; j <= mx; ++j)
                mem[i][j] = mem[i-1][j] || mem[i-1][j - curr];
        }

        return mem[n-2][mx];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    int TC;
    
    cin >> TC;

    while(TC--)
        cout << (sol.solve() ? "YES\n" : "NO\n");

    return 0;
}