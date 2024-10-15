class Solution {
public:
    int CalculateMaxProfit(vector<int>& prices, int n, int minPrice, int maxProfit) {

        // Loop To Keep Track Of The Required Prices & Profits
        for (int i = 0; i < n; i++) {

            minPrice = min(minPrice, prices[i]); // We need the minimum price
            maxProfit = max(maxProfit, prices[i] - minPrice); // This keeps in check of the maximum profit
        
        }

        //Returns the maximum profit obtained
        return maxProfit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();  // The size of the prices array
        int minPrice = INT_MAX; // To keep track of the minimum cost-price
        int maxProfit = 0;      // To keep track of the maximum profit

        // Function that we need to call to calculate
        int ResultantMaxProfit = CalculateMaxProfit(prices, n, minPrice, maxProfit);

        // Returns the maximum profit obtained
        return ResultantMaxProfit;
    }
};