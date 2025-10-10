/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
    if (!root) {
            return 0;
        }

        TreeNode* prev = nullptr;
        int minDiff = INT_MAX;
        ioT(root, prev, minDiff);
        return minDiff;
    }

    void ioT(TreeNode* node, TreeNode*& prev, int& minDiff) {
        if (!node) {
            return;
        }

        ioT(node->left, prev, minDiff);

        if (prev != nullptr) {
            minDiff = min(minDiff, abs(node->val - prev->val));
        }
        prev = node;

        ioT(node->right, prev, minDiff);
    }
};