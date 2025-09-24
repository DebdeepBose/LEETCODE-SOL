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
    bool isBalanced(TreeNode* root) { 
        return ifItsBalanced(root) != 0; 
    }

    int ifItsBalanced(TreeNode* node) {
        if (node == nullptr) {
            return 1; // height of empty tree
        }

        int left = ifItsBalanced(node->left);
        int right = ifItsBalanced(node->right);

        // if either subtree already unbalanced -> propagate failure
        if (left == 0 || right == 0) {
            return 0;
        }

        if (abs(left - right) <= 1) {
            return max(left, right) + 1; // return height if balanced
        }

        return 0; // mark as unbalanced
    }
};
