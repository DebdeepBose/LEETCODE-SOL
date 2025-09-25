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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> q;
        bool f = true;
        vector<vector<int>> ans;
        q.push(root);
        zlo(root, q, f, ans);
        return ans;
    }
    void zlo(TreeNode* node, queue<TreeNode*>& q, bool f,
             vector<vector<int>>& ans) {

        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                int frontVal = front->val;
                q.pop();
                tmp.push_back(frontVal);

                if (front->left != nullptr) {
                    q.push(front->left);
                }
                if (front->right != nullptr) {
                    q.push(front->right);
                }
            }
            if (!f) {
                reverse(tmp.begin(), tmp.end());
            }
            f = !f;
            ans.push_back(tmp);
        }
    }
};