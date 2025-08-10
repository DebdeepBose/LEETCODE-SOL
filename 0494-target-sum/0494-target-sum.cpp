class Solution {
public:
    map<pair<int,int>, int> dp;
    
    int helper(vector<int>& v, int t, int s, int i) {
        if (i == v.size()) {
            return s == t;
        }
        if (dp.count({i, s})) {
            return dp[{i, s}];
        }
        int plus = helper(v, t, s + v[i], i + 1);
        int minus = helper(v, t, s - v[i], i + 1);
        return dp[{i, s}] = plus + minus;
    }

    int findTargetSumWays(vector<int>& v, int t) {
        dp.clear();
        return helper(v, t, 0, 0);
    }
};
