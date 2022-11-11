/**
 * Codeforces Round #145 (Div. 2, ACM-ICPC Rules)
 * Problem C - Weather
 * TIME: 92 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <fstream>

using namespace std;

#define LIM 100000

class Solution {
    int arr[LIM], forw[LIM], back[LIM];
public:
    int solve()
    {
        int n, i, mn, ans;
        ifstream inp;

        inp.open("input.txt");

        inp >> n;
        for(i = 0; i < n; ++i) inp >> arr[i];

        inp.close();

        // ready forw
        forw[0] = (!arr[0] || arr[0] > 0);
        for(i = 1; i < n; ++i)
            forw[i] = forw[i-1] + (!arr[i] || arr[i] > 0);

        // ready back
        back[n-1] = (!arr[n-1] || arr[n-1] < 0);
        for(i = n-2; i >= 0; --i)
            back[i] = back[i+1] + (!arr[i] || arr[i] < 0);

        // ready ans
        ans = n;
        for(i = 1; i < n; ++i)
            ans = min(ans, forw[i-1]+back[i]);
        
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    ofstream out;

    out.open("output.txt");
    
    out << sol.solve() << '\n';

    out.close();

    return 0;
}