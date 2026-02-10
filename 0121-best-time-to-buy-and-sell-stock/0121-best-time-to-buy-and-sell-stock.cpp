class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int cur = v[0];
        int maxp = 0;
        for (int i = 0; i < n; i++) {
            maxp = max(maxp, v[i] - cur);
            cur = min(cur, v[i]);
        }
        return maxp;
    }
};