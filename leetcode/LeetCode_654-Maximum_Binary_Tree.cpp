/**
* LeetCode 654 - Maximum Binary Tree
* URL: https://leetcode.com/problems/maximum-binary-tree/
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    int find_max_pos(int left, int right, vector <int> arr)
    {
        int max_pos = left, max_val = arr[left];

        for(int i = left + 1; i <= right; ++i)
            if(arr[i] > max_val)
            {
                max_pos = i;
                max_val = arr[i];
            }

        return max_pos;
    }

    TreeNode * constructTree(int left, int right, vector <int> nums)
    {
        // BASE CASE
        if(left > right) return nullptr;

        int max_pos = find_max_pos(left, right, nums);
        TreeNode * newNode = new TreeNode(nums[max_pos]);

        newNode->left = constructTree(left, max_pos - 1, nums);
        newNode->right = constructTree(max_pos + 1, right, nums);

        return newNode;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(0, nums.size() - 1, nums);
    }
};

int main()
{
    vector <int> vec = { 3,2,1,6,0,5 };

    Solution solve;
    solve.constructMaximumBinaryTree(vec);
    
    return 0;
}
