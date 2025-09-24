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
    int maxDepth(TreeNode* root) {
        /*Yeah so like draw the tree and track it,
        you would observe that if the depth is 2, leetcode shows 3,
        well teh actual depth is indeed 3, so basically our final answer would
        have a +1 while we return it, in fact that will be necesaary at every
        setp*/

        // Self-Explanatory
        if (root == nullptr) {
            return 0;
        }

        // We first traverse left then right and store the depth in two
        // variables
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Now we return the max amongst the two with a +1
        return max(leftDepth, rightDepth) + 1;
    }
};