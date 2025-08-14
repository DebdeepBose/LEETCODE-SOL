class Solution {
public:
    void findIt(TreeNode* root, int t, vector<vector<int>>& ans,
                vector<int>& tmp) {
        if (root == nullptr) {
            return;
        }

        tmp.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            if (t - root->val == 0) {
                ans.push_back(tmp);
            }
        }

        else {
            findIt(root->left, t - root->val, ans, tmp);
            findIt(root->right, t - root->val, ans, tmp);
        }

        tmp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> ans;
        vector<int> tmp;
        findIt(root, t, ans, tmp);
        return ans;
    }
};
