class Solution {
public:
    int maxProfit(vector<int>& nums) {

        // Edge case: Less than 2 elements means no transaction possible
        if (nums.size() < 2) {
            return 0;
        } 

        // Initializing min_price as it can be reduced later
        int min_price = nums[0];

        // Initializing max_profit to 0
        int max_profit = 0; 

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < min_price) {
                min_price = nums[i]; // Update min price
            } else {
                max_profit = max(max_profit, nums[i] - min_price); // Update max profit
            }
        }
        return max_profit;
    }
};
