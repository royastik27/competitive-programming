/**
 * Codeforces Round #272 (Div. 2)
 * Problem B - Dreamoon and WiFi
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define LIM 11

class Solution
{
    char drazil[LIM], dreamoon[LIM];
    int len, finalValue, qmark;

    int solve(int pos, int sum)
    {
        if(pos == len)
        {
            if(sum == finalValue)
                return 1;
            else return 0;
        }

        if(dreamoon[pos] == '+')
            return solve(pos+1, sum + 1);
        else if(dreamoon[pos] == '-')
            return solve(pos+1, sum - 1);
        else
            return solve(pos+1, sum + 1) + solve(pos+1, sum - 1);
    }
    public:
    void getInput()
    {
        cin >> drazil >> dreamoon;
        
        len = finalValue = qmark = 0;
        for(int i = 0; drazil[i] != '\0'; ++i)
        {
            if(drazil[i] == '+') ++finalValue;
            else --finalValue;

            if(dreamoon[i] == '?') ++qmark;

            ++len;
        }

        return;
    }
    double answer()
    {
        return solve(0, 0) / (double)pow(2, qmark);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    cout << fixed << setprecision(9);

    sol.getInput();
    cout << sol.answer() << '\n';
    
    return 0;
}