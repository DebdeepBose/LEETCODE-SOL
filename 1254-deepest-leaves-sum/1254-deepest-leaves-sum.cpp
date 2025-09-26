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
    int deepestLeavesSum(TreeNode* root) {
        int depth = maxDepth(root);
        int deepLeafSum = 0;
        int depthTrack = 0;
        findDeepLeafSum(root, deepLeafSum, depthTrack, depth);

        return deepLeafSum;
    }
    int maxDepth(TreeNode* node) {

        if (!node) {
            return 0;
        }

        int left = maxDepth(node->left);
        int right = maxDepth(node->right);

        return max(left, right) + 1;
    }
    void findDeepLeafSum(TreeNode* node, int& deepLeafSum, int depthTrack,
                         int& depth) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            if (depthTrack == depth - 1) {
                deepLeafSum += node->val;
            }
            return;
        }

        findDeepLeafSum(node->left, deepLeafSum, depthTrack + 1, depth);
        findDeepLeafSum(node->right, deepLeafSum, depthTrack + 1, depth);
    }
};
