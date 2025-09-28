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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        deque<TreeNode*> q;
        q.push_back(root);
        vector<int> ans;
        rightView(q, ans);
        return ans;
    }
    void rightView(deque<TreeNode*> q, vector<int>& ans) {
        while (!q.empty()) {
            int n = q.size();
            TreeNode* back = q.back();
            int backVal = back->val;
            ans.push_back(backVal);
            for (int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                q.pop_front();
                if (front->left) {
                    q.push_back(front->left);
                }
                if (front->right) {
                    q.push_back(front->right);
                }
            }
        }
    }
};