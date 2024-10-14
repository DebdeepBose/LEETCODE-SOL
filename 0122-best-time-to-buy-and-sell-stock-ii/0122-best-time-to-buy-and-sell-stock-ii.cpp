class Solution {
public:
    int maxProfit(vector<int>& v) {
        if (v.size() == 1) {
            return 0;
        }
        int profit = 0;
        for (int i = 0; i < v.size() - 1; i++) {

            if (v[i + 1] > v[i]) {
                profit += v[i + 1] - v[i];
                i = i++;
            }
        }
        return profit;
    }
};