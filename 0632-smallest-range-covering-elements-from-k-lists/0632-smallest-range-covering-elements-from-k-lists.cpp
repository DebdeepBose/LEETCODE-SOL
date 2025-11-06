class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int maxi = INT_MIN;

        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            maxi = max(maxi, nums[i][0]);
        }

        vector<int> ans = {0, INT_MAX};

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int val = cur[0], row = cur[1], col = cur[2];

            if (maxi - val < ans[1] - ans[0]) ans = {val, maxi};

            if (col + 1 == nums[row].size()) break;

            int nextVal = nums[row][col + 1];
            pq.push({nextVal, row, col + 1});
            maxi = max(maxi, nextVal);
        }

        return ans;
    }
};
