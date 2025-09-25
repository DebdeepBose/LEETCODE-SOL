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
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        int finalVal = help(root, mx);
        return mx;
    }
    int help(TreeNode* node, int& mx) {
        if (node == nullptr) {
            return 0;
        }

        int leftVal = max(0, help(node->left, mx));
        int rightVal = max(0, help(node->right, mx));

        mx = max(mx, node->val + leftVal + rightVal);

        return node->val + max(leftVal, rightVal);
    }
};