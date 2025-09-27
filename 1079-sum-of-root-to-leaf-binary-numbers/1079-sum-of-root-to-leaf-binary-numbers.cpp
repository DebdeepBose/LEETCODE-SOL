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
    int sumRootToLeaf(TreeNode* root) {
        string binaryString = "";
        int sum = 0;
        findNum(root, binaryString, sum);
        return sum;
    }
    void findNum(TreeNode* node, string binaryString, int& sum) {
        if (!node) {
            return;
        }
        binaryString += to_string(node->val);

        if (!node->left && !node->right) {
            int decimalVal = binaryToDecimal(binaryString);
            sum += decimalVal;
        }

        findNum(node->left, binaryString, sum);
        findNum(node->right, binaryString, sum);
    }
    int binaryToDecimal(string binaryString) {

        int decimal = 0;
        reverse(binaryString.begin(), binaryString.end());

        for (int i = 0; i < binaryString.size(); i++) {
            if (binaryString[i] == '1') {
                decimal += pow(2, i);
            }
        }

        return decimal;
    }
};