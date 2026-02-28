class Solution {
    vector<int> solve(vector<int>& nums, bool even) {
        int op = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int num : nums) {
            if ((num % 2 != 0 && even) || (num % 2 == 0 && !even)) {
                op++;
                maxi = max(maxi, num - 1);
                mini = min(mini, num + 1);
            } else {
                maxi = max(maxi, num);
                mini = min(mini, num);
            }
            even = !even;
        }
        return {op, maxi - mini};
    }

public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return {0, 0};
        }

        unordered_set<int> st(nums.begin(), nums.end());
        if (st.size() == 1) {
            return {n / 2, 1};
        }

        vector<int> res1 = solve(nums, 0);
        vector<int> res2 = solve(nums, 1);

        if (res1[0] == res2[0]) {
            if (res1[1] < res2[1]) {
                return res1;
            } else {
                return res2;
            }
        } else {
            if (res1[0] < res2[0]) {
                return res1;
            } else {
                return res2;
            }
        }
    }
};