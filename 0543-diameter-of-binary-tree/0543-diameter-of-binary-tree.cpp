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
    int diameterOfBinaryTree(TreeNode* root) {
        /*Idk man i always forget how to solve this question anyways,
        the question says the diameter can/cannot contain the root, so the
        apprwaoch of finding the maxLeftDepth and maxRightDepth and adding isnt
        gonna work here*/

        // Lets first initialize basic stuff
        int maxDiameter = 0;
        // Ye we would be needing this

        /*Basically we gon find the maxDiameter for EVERY NODE, and since we
         * will be useg max funciton, the maxDiameter will be stored anyways*/

        findDiameter(root, maxDiameter);

        return maxDiameter;
    }

    int findDiameter(TreeNode* node, int& maxDiameter) {

        if (node == nullptr) {
            return 0;
        }

        /*So basically depth function but for everynode and, at every node
         * when its done getting its left and right depth value we will just add
         * it and compare wiht the maxdiamter value and take the maximum amongst
         * them*/

        int maxLeftDepth = findDiameter(node->left, maxDiameter);
        int maxRightDepth = findDiameter(node->right, maxDiameter);

        maxDiameter = max(maxDiameter, maxLeftDepth + maxRightDepth);

        return max(maxLeftDepth, maxRightDepth) + 1;
    }
};