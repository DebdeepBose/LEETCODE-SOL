/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return check(root->left, root->right);
    }

    bool check(TreeNode* l, TreeNode* r) {
        if (!l && !r) {
            return true;
        }
        if (!l && r || l && !r) {
            return false;
        }
        if (l->val != r->val) {
            return false;
        }

        bool leftCheck = check(l->left, r->right);
        bool rightCheck = check(l->right, r->left);

        if (!leftCheck || !rightCheck) {
            return false;
        }
        return true;
    }
};
