class Solution {
public:
    long long getDescentPeriods(vector<int>& v) {
        long long ans = 1;
        long long c = 1;
        int n = v.size();
        for (int i = 1; i < n; i++) {
            if (v[i] + 1 == v[i - 1]) {
                c++;
            } else {
                c = 1;
            }
            ans += c;
        }
        return ans;
    }
};