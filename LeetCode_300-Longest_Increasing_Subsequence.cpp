/**
* LeetCode 300 - Longest Increasing Subsequence
* Time: 128 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int LIS[2500], ara[2500], len;

    int find_LIS(int pos)
    {
        int i;

        if(LIS[pos] != -1)
            return LIS[pos];

        LIS[pos] = 0;
        for(i = pos + 1; i < len; ++i)
        {
            if(ara[i] > ara[pos])
            {
                LIS[pos] = max(LIS[pos], find_LIS(i));
            }
        }

        return ++LIS[pos];
    }
public:
    int lengthOfLIS(vector<int>& nums) {

        int i, res;
        len = nums.size();

        for(i = 0; i < len; ++i)
        {
            ara[i] = nums[i];
            LIS[i] = -1;
        }

        res = 0 ;
        for(i = 0; i < len; ++i)
            res = max(res, find_LIS(i));

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
