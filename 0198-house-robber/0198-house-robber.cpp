class Solution {
public:
    int findSub(vector<int>& v, int n, vector<int>& dp) {
        if (n <= 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        int take = v[n - 1] + findSub(v, n - 2, dp); // Taking it
        int skip = 0 + findSub(v, n - 1, dp);        // Not taking that element
        return dp[n] = max(take, skip);
    }
    int rob(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n + 1, -1); // yeah we can totally use
        // dp(n,-1) , cuz like if there are 3 elements we have f0 f1 f2 states 
        //just gotta tweak the rec func
        return findSub(v, n, dp);
    }
};