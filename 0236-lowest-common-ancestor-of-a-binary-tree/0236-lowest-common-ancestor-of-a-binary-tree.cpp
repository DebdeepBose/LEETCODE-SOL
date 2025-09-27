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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }
        if (root == p || root == q) {
            return root;
        }
        return findLCA(root, p, q);
    }
    TreeNode* findLCA(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) {
            return nullptr;
        }
        if (node == p || node == q) {
            return node;
        }

        TreeNode* left = findLCA(node->left, p, q);
        TreeNode* right = findLCA(node->right, p, q);

        if (left && right) {
            return node;
        }
        return left ? left : right;
    }
};