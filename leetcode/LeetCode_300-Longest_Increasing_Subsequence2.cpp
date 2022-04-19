/**
* LeetCode 300 - Longest Increasing Subsequence
* Iterative Method
* Optimized Memory
* Time: 216 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int LIS[2500];
public:
    int lengthOfLIS(vector<int>& nums) {

        int i, j, res, len = nums.size();

        for(i = len - 1; i >=0; --i)
        {
            LIS[i] = 0;
            for(j = i + 1; j < len; ++j)
            {
                if(nums[j] > nums[i])
                    LIS[i] = max(LIS[i], LIS[j]);
            }

            ++LIS[i];
        }

        res = 0 ;
        for(i = 0; i < len; ++i)
            res = max(res, LIS[i]);

        return res;
    }
};

int main()
{
    Solution solve;
    int ara[] = { 10, 9, 2, 5, 3, 7, 101, 18 };
    vector <int> vec(ara, ara + 8);

    cout << solve.lengthOfLIS(vec) << '\n';

    return 0;
}
