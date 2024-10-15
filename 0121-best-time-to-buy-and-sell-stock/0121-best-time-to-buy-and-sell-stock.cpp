class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int profit = 0;
        int minprice = INT_MAX;
        for (int i = 0; i < n; i++) {
            minprice = min(minprice, v[i]);
            profit = max(profit, v[i] - minprice);
        }
        return profit;
    }
};
