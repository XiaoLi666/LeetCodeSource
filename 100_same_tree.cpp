/**
 * Author: ZILI WANG
 * Date: 13th Jan 2016
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        else if (p == nullptr || q == nullptr) {
            return false;
        }
        return (p->val==q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
