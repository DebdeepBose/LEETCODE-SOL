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
    int goodNodes(TreeNode* root) {
        int c = 0;
        int maxi = root->val;
        cn(root, c, maxi);
        return c;
    }
    void cn(TreeNode* node, int& c, int maxi) {
        if (!node) {
            return;
        }
        if (node->val >= maxi) {
            c++;
            maxi = node->val;
        }

        cn(node->left, c, maxi);
        cn(node->right, c, maxi);
    }
};