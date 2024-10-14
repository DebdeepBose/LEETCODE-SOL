class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;  
        }
        int minPrice = prices[0]; 
        int maxProfit = 0;  
        for (int i = 1; i < n; i++) {
            if (prices[i] > minPrice) {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            } else {
                minPrice = prices[i];  
            }
        }
        return maxProfit;
    }
};
