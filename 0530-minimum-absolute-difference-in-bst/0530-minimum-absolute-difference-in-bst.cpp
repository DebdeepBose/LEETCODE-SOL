class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
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
