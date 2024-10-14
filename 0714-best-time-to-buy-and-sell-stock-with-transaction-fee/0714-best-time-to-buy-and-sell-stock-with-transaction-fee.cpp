class Solution {
public:
    int maxProfit(vector<int>& v, int k) {
        int n = v.size();
        int income = INT_MIN;
        int profit = 0;
        for (int i = 0; i < n; i++) {
            income = max(income, profit - v[i]);
            profit = max(profit, income + v[i] - k);
        }
        return profit;
    }
};