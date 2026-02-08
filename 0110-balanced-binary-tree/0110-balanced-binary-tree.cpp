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
    bool isBalanced(TreeNode* root) {
        /*There are some questions that follow a very specific pattern
        and there arent many solutions to this so yeah just follow through*/

        /*We'll just pass the root to another function and well if that function
        returns anything apart from -1 then it's true, Why -1 u ask? yeah i have
        no answer for that , >0 wasnt being accepted so its just an
        alternative*/

        return checkIfBalanced(root) != -1;
    }

    int checkIfBalanced(TreeNode* node) {

        // Well this is one reason if currentNode becomes null we gotta return 0
        // But that messes up my return checIfBalance > 0, so i had to use -1
        if (node == nullptr) {
            return 0;
        }

        // Now we check left and right depth
        int leftDepth = checkIfBalanced(node->left);
        /*Understadn this leftDepth also stores a value so if that value is -1
        at any point we return -1, same for right depth, usually happens for
        skewed trees*/
        if (leftDepth == -1) {
            return -1;
        }

        // Same priciple as leftDepth
        int rightDepth = checkIfBalanced(node->right);
        if (rightDepth == -1) {
            return -1;
        }

        // I mean yeah it has to be height balanced
        if (abs(leftDepth - rightDepth) > 1) {
            return -1;
        }

        return max(leftDepth, rightDepth) + 1;
    }
};