class Solution {
public:
    void help(TreeNode* node, int& sum, bool isLeft) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr && isLeft) {
            sum += node->val;
            return;
        }

        help(node->left, sum, true);
        help(node->right, sum, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int sum = 0;
        help(root, sum, false);
        return sum;
    }
};
