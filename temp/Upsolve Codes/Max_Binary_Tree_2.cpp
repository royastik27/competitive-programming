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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {

        TreeNode * newNode = new TreeNode(val);

        if(!root) return newNode;
        else if(val > root->val)
        {
            newNode->left = root;
            return newNode;
        }

        TreeNode * parent, * current;
        parent = current = root;

        while(!current)
        {
            if(!parent->left) current = parent->left;
            else if(!parent->right) current = parent->right;
            else if(val > parent->left->val) { current = parent->left; break; }
            else if(val > parent->right->val) { current = parent->right; break; }
            else
                parent = parent->left;
        }

        if(!current)
        {
            if(!parent->left) parent->left = newNode;
            else parent->right = newNode;
        }
        else
        {   newNode->left = current;

            if(current == parent->left)
                parent->left = newNode;
            else parent->right = newNode;
        }

        return root;
    }
    void printTree(TreeNode * node)
    {
        if(!node) cout << "null ";
        else
        {
            cout << node->val << ' ';
            printTree(node->left);
            printTree(node->right);
        }

        return;
    }
};

int main()
{
    vector <int> vec = { 1, 4, 2, 3 };
    int val = 5;
    Solution solve;

    TreeNode * root = solve.constructMaximumBinaryTree(vec);

    cout << "\nTree: ";
    solve.printTree(root);
    cout << '\n';

    cout << "\nAFTER INSERTING:";
    cout << "\nTree: ";
    root = solve.insertIntoMaxTree(root, val);
    solve.printTree(root);
    cout << "\n\n";
    
    return 0;
}
