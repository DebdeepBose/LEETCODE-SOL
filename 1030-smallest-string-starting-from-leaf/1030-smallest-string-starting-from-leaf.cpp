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
    string smallestFromLeaf(TreeNode* root) {
        vector<string> v;
        string s = "";
        allS(root, v, s);
        sort(v.begin(), v.end());
        return v[0];
    }
    void allS(TreeNode* node, vector<string>& v, string s) {
        if (!node) {
            return;
        }
        s += char('a' + node->val);
        if (!node->left && !node->right) {
            reverse(s.begin(), s.end());
            v.push_back(s);
            return;
        }
        allS(node->left, v, s);
        allS(node->right, v, s);
    }
};