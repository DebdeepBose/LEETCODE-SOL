class Solution {
public:
    int maxSum(vector<int>& v) {
        int n = v.size();
        int sum = 0;
        int maxSum = INT_MIN;
        int maxNeg = INT_MIN;
        set<int> st;
        for (int i = 0; i < n; i++) {
            if (st.find(v[i]) == st.end() && v[i] > 0) {
                sum += v[i];
                st.insert(v[i]);
            } else if (v[i] <= 0) {
                maxNeg = max(maxNeg, v[i]);
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum == 0 ? maxNeg : maxSum;
    }
};