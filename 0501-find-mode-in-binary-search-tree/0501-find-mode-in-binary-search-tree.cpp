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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        fill(root, mp);
        int maxi = INT_MIN;
        vector<int> ans;
        for (auto e : mp) {
            if (e.second >= maxi) {
                maxi = e.second;
            }
        }
        for (auto e : mp) {
            if (e.second == maxi) {
                ans.push_back(e.first);
            }
        }
        return ans;
    }
    void fill(TreeNode* node, unordered_map<int, int>& mp) {
        if (!node) {
            return;
        }
        mp[node->val]++;
        fill(node->left, mp);
        fill(node->right, mp);
    }
};