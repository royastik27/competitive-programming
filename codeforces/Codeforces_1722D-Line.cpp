/**
 * Codeforces Round #817 (Div. 4)
 * Problem D - Line
 * TIME: 78 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution {

public:
    void solve()
    {
        int n, i;
        long long int sum = 0;
        string str;

        cin >> n >> str;

        for(i = 0; i < n; ++i)
        {
            if(str[i] == 'L') sum += i;
            else sum += n - i - 1;
        }

        int half = n / 2, cnt = 0;
        for(i = 0; i < half; ++i)
        {
            if(str[i] != 'R')
            {
                ++cnt;
                sum -= i;
                sum += n - i - 1;
                cout << sum << ' ';
            }

            if(str[n-i-1] != 'L')
            {
                ++cnt;
                sum -= i;
                sum += n - i - 1;
                cout << sum << ' ';
            }
        }

        for(i = cnt; i < n; ++i)
            cout << sum << ' ';
        cout << '\n';
        
        return;
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
        sol.solve();
    
    return 0;
}