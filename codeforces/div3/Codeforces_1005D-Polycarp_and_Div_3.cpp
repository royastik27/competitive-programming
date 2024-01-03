/**
* Codeforces Round 496 (Div. 3)
* Problem D - Polycarp and Div 3
* TIME: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    void solve()
    {
        int n, last[3], ans, rem, pre_sum, i;
        vector <int> mem;
        string str;

        cin >> str;

        n = str.length();
        str = "#" + str;

        mem.resize(n+1);

        ans = pre_sum = 0;
        mem[0] = 0;
        
        last[0] = 0;
        last[1] = last[2] = -1;

        for(i = 1; i <= n; ++i) {
            
            pre_sum += int(str[i] - '0');

            rem = pre_sum % 3;

            if(last[rem] == -1)
                mem[i] = mem[i-1];
            else
                mem[i] = max(mem[i-1], 1 + mem[last[rem]]);

            ans = max(ans, mem[i]);

            last[rem] = i;
        }

        cout << ans << '\n';
        
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