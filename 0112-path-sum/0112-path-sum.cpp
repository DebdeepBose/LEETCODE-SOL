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
    bool findSum(TreeNode* root, int t) {
        if (root == nullptr) {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return (t - root->val) == 0;
        }

        bool l = findSum(root->left, t - root->val);
        bool r = findSum(root->right, t - root->val);

        return l || r;
    }
    bool hasPathSum(TreeNode* root, int t) {
        bool f = findSum(root, t);
        return f;
    }
};