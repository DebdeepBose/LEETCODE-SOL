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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int depth = 0;
        pair<int, int> maxSum = {INT_MIN, depth};
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* frontNode = q.front();
                int frontVal = frontNode->val;
                q.pop();
                sum += frontVal;
                if (frontNode->left != nullptr) {
                    q.push(frontNode->left);
                }
                if (frontNode->right != nullptr) {
                    q.push(frontNode->right);
                }
            }
            if (maxSum.first < sum) {
                maxSum.first = sum;
                maxSum.second = depth;
            }
            depth++;
        }
        return maxSum.second + 1;
    }
};