/**
 * LeetCode 1863 - Sum of All Subset XOR Totals
 * Time: 0 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector <int> num;

    int solve(int i, int XORSUM)
    {
        if(i == num.size()) return XORSUM;

        return solve(i+1, XORSUM) + solve(i+1, XORSUM ^ num[i]);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        num = nums;
        return solve(0, 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    vector <int> nums = { 3,4,5,6,7,8 };
    cout << sol.subsetXORSum(nums) << '\n';
    
    return 0;
}