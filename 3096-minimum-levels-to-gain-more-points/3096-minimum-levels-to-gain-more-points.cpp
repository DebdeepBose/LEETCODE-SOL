class Solution {
public:
    int minimumLevels(vector<int>& v) {
        int n = v.size();
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += (v[i] ? 1 : -1);
        }

        // Consider every element as a split and ccheck if prefSum > sufficSum
        int prefSum = 0;
        // we go till n - 1 cuz we atleast need to have 1 element for suffix sum
        for (int i = 0; i < n - 1; i++) {
            prefSum += (v[i] ? 1 : -1);
            int suffSum = totalSum - prefSum;
            if (prefSum > suffSum) {
                return i + 1;
            }
        }
        return -1;
    }
};