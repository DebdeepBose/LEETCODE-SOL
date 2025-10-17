class Solution {
public:
    int help(int i, int mask, int change, int k, string& s, unordered_map<long long, int>& dp) {
        int n = s.size();
        if (i == n) {
            return 1;
        }

        long long currState = ((long long)i << 27) | ((long long)mask << 1) | change;
        if (dp.find(currState) != dp.end()) {
            return dp[currState];
        }

        int val = s[i] - 'a';
        int newMask = mask | (1 << val);
        int count = __builtin_popcount(newMask);

        int ans = 0;
        int maxi = 0;

        if (count > k) {
            ans = 1 + help(i + 1, 1 << val, change, k, s, dp);
            maxi = std::max(maxi, ans);
        } else {
            ans = help(i + 1, newMask, change, k, s, dp);
            maxi = std::max(maxi, ans);
        }

        if (change) {
            return dp[currState] = maxi;
        }

        for (int j = 0; j < 26; j++) {
            int newMask2 = mask | (1 << j);
            int count2 = __builtin_popcount(newMask2);

            if (count2 > k) {
                maxi = std::max(maxi, 1 + help(i + 1, 1 << j, 1, k, s, dp));
            } else {
                maxi = std::max(maxi, help(i + 1, newMask2, 1, k, s, dp));
            }
        }

        return dp[currState] = maxi;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long, int> dp;
        return help(0, 0, 0, k, s, dp);
    }
};
