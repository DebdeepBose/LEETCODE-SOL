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
    bool hasPathSum(TreeNode* root, int k) { return check(root, k); }
    bool check(TreeNode* node, int k) {
        if (node == nullptr) {
            return false;
        }
        if (node->right == nullptr && node->left == nullptr) {
            if (k - node->val == 0) {
                return true;
            }
            return false;
        }

        k -= node->val;
        bool left = check(node->left, k);
        bool right = check(node->right, k);

        return left || right;
    }
};