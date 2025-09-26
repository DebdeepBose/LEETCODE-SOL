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
    bool isUnivalTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        int rootVal = root->val;
        return checkIfUniValTree(root, rootVal);
    }
    bool checkIfUniValTree(TreeNode* node, int rootVal) {
        if (!node) {
            return true;
        }

        if (node->val != rootVal) {
            return false;
        }

        bool left = checkIfUniValTree(node->left, rootVal);
        bool right = checkIfUniValTree(node->right, rootVal);

        return left && right;
    }
};