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
    int countNodes(TreeNode* root) {
        int c = 0;
        countN(root, c);
        return c;
    }
    void countN(TreeNode* node, int& c) {
        if (node == nullptr) {
            return;
        }
        c++;
        countN(node->left, c);
        countN(node->right, c);
    }
};