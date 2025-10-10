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

        vector<int> v;
        ioT(root, v);

        int minDiff = INT_MAX;

        for (int i = 1; i < v.size(); i++) {
            minDiff = min(minDiff, v[i] - v[i - 1]);
        }

        return minDiff;
    }
    void ioT(TreeNode* node, vector<int>& v) {
        if (!node) {
            return;
        }

        ioT(node->left, v);
        v.push_back(node->val);
        ioT(node->right, v);
    }
};