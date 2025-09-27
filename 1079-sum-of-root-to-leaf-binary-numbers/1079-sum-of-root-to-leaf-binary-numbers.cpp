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
        int n = binaryString.size();
        for (int i = 0; i < n; i++) {
            if (binaryString[i] == '1') {
                decimal += (1 << (n - i - 1));
            }
        }
        return decimal;
    }
};
