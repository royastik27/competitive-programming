/**
 * LeetCode 1863 - Sum of All Subset XOR Totals
 * Time: 0 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    vector <string> ans;
    int a[10] = { 8, 4, 2, 1, 32, 16, 8, 4, 2, 1 }, turnedOn;

    void solve(int hour = 0, int min = 0, int count = 0, int state = 0)
    {
        // BASE CASE 1
        if(count == turnedOn)
        {
            if(hour < 12 && min < 60)
            {
                // for hours
                string str = to_string(hour) + ":";

                // for minutes
                if(min < 10) str += "0";
                str += to_string(min);

                ans.push_back(str);
            }
            return;
        }
        
        // BASE CASE 2
        if(state == 10) return;

        // RECURSIVE CALLS
        solve(hour, min, count, state + 1);

        if(state < 4)   hour += a[state];
        else min += a[state];

        solve(hour, min, count+1, state + 1);

        return;
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        this->turnedOn = turnedOn;
        solve();
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    int turnedOn = 4;

    vector <string> vec = sol.readBinaryWatch(turnedOn);

    cout << "Result:\n";
    for(vector <string>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
    
    return 0;
}