class Solution {
public:
    void help(TreeNode* node, vector<int>& sum, bool isLeft) {
        if (node == nullptr) {
            return;
        }

        if (!node->left && !node->right && isLeft) {
            sum.push_back(node->val);
            return;
        }

        help(node->left, sum, true);
        help(node->right, sum, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        vector<int> sum;
        help(root, sum, false);
        return accumulate(sum.begin(), sum.end(), 0);
    }
};
