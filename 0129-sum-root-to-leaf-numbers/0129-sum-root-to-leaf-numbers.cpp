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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string s = "";
        help(root, s, sum);
        return sum;
    }
    void help(TreeNode* node, string s, int& sum) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            int y = node->val;
            s += to_string(y);
            sum += stoi(s);
            return;
        }
        int x = node->val;
        s += to_string(x);
        help(node->left, s, sum);
        help(node->right, s, sum);
    }
};