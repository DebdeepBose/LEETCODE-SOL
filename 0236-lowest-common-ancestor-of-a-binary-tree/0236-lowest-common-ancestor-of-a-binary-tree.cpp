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
        return check(root, p, q); 
    }

    TreeNode* check(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) {
            return nullptr;
        }
        if (node == p || node == q) {
            return node;
        }

        TreeNode* leftLCA = check(node->left, p, q);
        TreeNode* rightLCA = check(node->right, p, q);

        if (leftLCA && rightLCA) {
            return node;
        }
        if (leftLCA) {
            return leftLCA; 
        }
        return rightLCA; 
    }
};
