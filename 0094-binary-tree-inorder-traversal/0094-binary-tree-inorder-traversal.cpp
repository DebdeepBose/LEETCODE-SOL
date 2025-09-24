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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        ioT(root, ans);
        return ans;
    }
    void ioT(TreeNode* node, vector<int>& ans) {
        if (node == nullptr) {
            return;
        }

        ioT(node->left, ans);
        ans.push_back(node->val);
        ioT(node->right, ans);
    }
};