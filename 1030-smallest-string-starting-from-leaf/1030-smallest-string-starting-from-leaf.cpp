/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string best = "~";
        string path = "";
        allStrings(root, path, best);
        return best;
    }

    void allStrings(TreeNode* node, string path, string& best) {
        if (!node) {
            return;
        }

        path += char('a' + node->val);

        if (!node->left && !node->right) {
            reverse(path.begin(), path.end());
            if (path < best) {
                best = path;
            }
            return;
        }

        allStrings(node->left, path, best);
        allStrings(node->right, path, best);
    }
};
