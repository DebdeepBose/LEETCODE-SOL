class Solution {
public:
    void gen(int n, vector<vector<int>>& ans, vector<int>& tmp,
             vector<int>& nums, int i) {
        if (i == n) {
            ans.push_back(tmp);
            return;
        }

        tmp.push_back(nums[i]);
        gen(n, ans, tmp, nums, i + 1);
        tmp.pop_back();
        gen(n, ans, tmp, nums, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> tmp;
        gen(n, ans, tmp, nums, 0);

        return ans;
    }
};