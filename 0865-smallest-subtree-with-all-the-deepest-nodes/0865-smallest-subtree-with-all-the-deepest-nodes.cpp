class Solution {
public:
    int maxDep = 0;
    TreeNode* ans = nullptr;

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

    int dfs(TreeNode* node, int depth) {
        if (!node) {
            maxDep = max(maxDep, depth);
            return depth;
        }

        int leftDepth = dfs(node->left, depth + 1);
        int rightDepth = dfs(node->right, depth + 1);

        if (leftDepth == maxDep && rightDepth == maxDep) {
            ans = node;
        }

        return max(leftDepth, rightDepth);
    }
};
