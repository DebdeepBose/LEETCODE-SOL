class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long> sp(n);
        for (int i = 0; i < n; i++) {
            sp[i] = 1LL * strategy[i] * prices[i];
        }

        long long baseline = 0;
        for (long long x : sp) baseline += x;

        int h = k / 2;

        long long oldSum = 0;
        for (int i = 0; i < k; i++) oldSum += sp[i];

        long long newSum = 0;
        for (int i = h; i < k; i++) newSum += prices[i];

        long long maxDiff = max(0LL, newSum - oldSum);

        for (int r = k; r < n; r++) {
            int l = r - k + 1;

            oldSum += sp[r] - sp[l - 1];
            newSum += prices[r];
            newSum -= prices[l - 1 + h];

            maxDiff = max(maxDiff, newSum - oldSum);
        }

        return baseline + maxDiff;
    }
};
