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
private:
    int toDeci(string s) {
        int ans = 0;
        int mul = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            ans += mul * (s[i] - '0');
            mul *= 2;
        }
        return ans;
    }
    void calcSum(TreeNode* node, string& s, int& sum) {
        if (!node) {
            return;
        }

        s.push_back(node->val + '0');

        if (!node->left && !node->right) {
            sum += toDeci(s);
        } else {
            calcSum(node->left, s, sum);
            calcSum(node->right, s, sum);
        }

        s.pop_back();
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        string s;
        int sum = 0;
        calcSum(root, s, sum);
        return sum;
    }
};