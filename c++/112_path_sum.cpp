/*
 * Author: Zili Wang
 * Date: 26th Jan 2016
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        
        // reach the leaf node
        if (!root->left && !root->right) {
            sum -= root->val;
            if (sum == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        
        int updatedSum = sum - root->val;
        return hasPathSum(root->left, updatedSum) || hasPathSum(root->right, updatedSum);
    }
};
