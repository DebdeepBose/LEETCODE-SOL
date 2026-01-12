class Solution {
public:
    int maxNorm(vector<int>& a, vector<int>& b) {
        return max(abs(a[0] - b[0]), abs(a[1] - b[1]));
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& v) {
        int ans = 0;
        vector<int> prev = v[0];
        for (auto e : v) {
            ans += maxNorm(e, prev);
            prev = e;
        }
        return ans;
    }
};