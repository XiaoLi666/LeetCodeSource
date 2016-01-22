/*
 * Author: Zili Wang
 * Date: 22nd Jan 2016
 * Remarks: Idea from internet "http://blog.csdn.net/xudli/article/details/46838747"
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
    // this is a binary search tree
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q) {
        if(root==nullptr||p==nullptr||q==nullptr)
            return nullptr;  
          
        if(max(p->val,q->val) < root->val) {  
            return lowestCommonAncestor(root->left, p, q);  
        }
        else if(min(p->val,q->val) > root->val) {  
            return lowestCommonAncestor(root->right, p, q);  
        }
        else
            return root;  
    }
};
