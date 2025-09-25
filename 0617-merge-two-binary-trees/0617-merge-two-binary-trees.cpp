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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        /*K so unlike our usual called functions which are either void/int this
         * one's gonna be TreeNode* */

        return mergeNodes(root1, root2);
    }
    TreeNode* mergeNodes(TreeNode* node1, TreeNode* node2) {
        /* Get this if one of the trees have a node and another doesnt,
        we cant simply add null to the value, doesnt work like that.
        In that case we gotta connect the previous pointer to existing node
        from whichever tree there is*/

        /*BTW for the sake of space optimization whatever is our result we
        are storing it in Tree1 itslef*/

        /*If node1 is null but not node2 then we return node2 cuz we gotta
        connect it tree 1*/
        if (!node1 && !node2) {
            return node1; // Yeah cuz we working with tree1
        }

        if (!node1 && node2) {
            return node2;
        }

        // Similar stuff
        if (node1 && !node2) {
            return node1;
        }

        node1->val += node2->val;

        // Gotta connect node1->left to a valid treenode returned by recurion
        node1->left = mergeNodes(node1->left, node2->left);

        // Same for node1->right
        node1->right = mergeNodes(node1->right, node2->right);

        // By default we return node1

        return node1;
    }
};