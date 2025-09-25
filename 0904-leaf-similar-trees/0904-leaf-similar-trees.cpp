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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ls1;
        vector<int> ls2;
        getLeaf(root1, ls1);
        getLeaf(root2, ls2);
        return ls1 == ls2;
    }
    void getLeaf(TreeNode* node, vector<int>& v) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            v.push_back(node->val);
            return;
        }
        getLeaf(node->left, v);
        getLeaf(node->right, v);
    }
};