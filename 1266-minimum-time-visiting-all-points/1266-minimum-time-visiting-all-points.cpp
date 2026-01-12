class Solution {
public:
    int maxNorm(vector<int>& P, vector<int>& Q) {
        return max(abs(P[0] - Q[0]), abs(P[1] - Q[1]));
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