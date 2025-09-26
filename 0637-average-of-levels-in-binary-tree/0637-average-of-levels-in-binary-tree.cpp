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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> levels;
        vector<double> ans;
        q.push(root);
        loT(root, q, levels);
        for (auto e : levels) {
            double sum = 0;
            double size = e.size();
            for (auto ee : e) {
                sum += ee;
            }
            double avg = sum / size;
            ans.push_back(avg);
        }
        return ans;
    }
    void loT(TreeNode* node, queue<TreeNode*>& q, vector<vector<int>>& levels) {
        if (node == nullptr) {
            return;
        }
        while (!q.empty()) {
            vector<int> tmp;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* frontNode = q.front();
                int front = frontNode->val;
                q.pop();
                tmp.push_back(front);
                if (frontNode->left != nullptr) {
                    q.push(frontNode->left);
                }
                if (frontNode->right != nullptr) {
                    q.push(frontNode->right);
                }
            }
            levels.push_back(tmp);
        }
    }
};