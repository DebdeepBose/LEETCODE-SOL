class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();

        int profit = 0;
        int cur = v[0];
        for (int i = 1; i < n; i++) {
            profit = max(profit, v[i] - cur);
            cur = min(cur, v[i]);
        }
        return profit;
    }
};