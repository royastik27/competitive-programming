/**
* Codeforces Round 859 (Div. 4)
* Problem G2 - Subsequence Addition (Hard Version)
* TIME: 77 ms
* AUTHOR: Astik Roy
**/


#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;

#define LIM 200000

class Solution
{
    int n, arr[LIM];
    ll sum;
public:
    bool solve()
    {
        int i;

        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> arr[i];

        sort(arr, arr+n);

        // considering first element
        if(arr[0] != 1)
            return false;

        // considering rests
        sum = 1;

        for(i = 1; i < n; ++i)
        {
            if(arr[i] > sum)
                return false;

            sum += arr[i];
        }

        return true;
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