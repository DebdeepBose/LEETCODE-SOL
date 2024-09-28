class Solution {
public:
    long long maximumTotalSum(vector<int>& v) {
        int n = v.size();
        sort(v.rbegin(), v.rend());
        long long ans = 0;
        int prev = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (v[i] < prev) {
                ans += v[i];
                prev = v[i];
            } else {
                ans += prev - 1;
                prev--;
            }
            if (prev == 0) return -1;
        }
        return ans;
    }
};
