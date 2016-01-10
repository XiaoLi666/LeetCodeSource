/*
 Author: ZILI WANG
 Date: 10th Jan 2016
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if(root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int left_count = 0;
        int right_count = 0;

        if (root->left)
            left_count = maxDepth(root->left);
        if (root->right)
            right_count = maxDepth(root->right);

        return left_count > right_count ? left_count + 1 : right_count + 1;
    }
};
