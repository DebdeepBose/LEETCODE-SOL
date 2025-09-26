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
        vector<double> levels;
        q.push(root);
        loT(root, q, levels);
        return levels;
    }
    void loT(TreeNode* node, queue<TreeNode*>& q, vector<double>& levels) {
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
            double sum = accumulate(tmp.begin(), tmp.end(), 0.0);
            double size = tmp.size();
            double avg = sum / size;
            levels.push_back(avg);
        }
    }
};