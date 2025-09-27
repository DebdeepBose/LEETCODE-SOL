class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxw = 0;
        help(q, maxw);
        return maxw;
    }

    void help(queue<pair<TreeNode*, unsigned long long>> q, int &maxw) {
        while (!q.empty()) {
            int n = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = left;
            for (int i = 0; i < n; i++) {
                auto [node, idx] = q.front(); q.pop();
                right = idx;
                if (node->left) {
                    q.push({node->left, 2 * idx});
                }
                if (node->right) {
                    q.push({node->right, 2 * idx + 1});
                }
            }
            maxw = max(maxw, (int)(right - left + 1));
        }
    }
};
