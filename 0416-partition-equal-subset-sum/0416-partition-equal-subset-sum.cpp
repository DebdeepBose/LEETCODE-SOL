class Solution {
public:
    bool canPartition(vector<int>& v) {
        int n = v.size();
        int sum = accumulate(v.begin(), v.end(), 0);

        // If total sum is odd, can't divide into equal subsets
        if (sum % 2 != 0) 
        {
            return false;
        }

        int target = sum / 2;

        // 1D DP: dp[j] means: can we make sum j using some subset
        vector<bool> dp(target + 1, false);
        dp[0] = true;  // Base case: sum 0 is always possible

        for (int i = 0; i < n; i++) {
            int curr = v[i];

            // Iterate in reverse to avoid using the same element twice
            for (int j = target; j >= curr; j--) {
                dp[j] = dp[j] || dp[j - curr];
            }
        }

        return dp[target];
    }
};
