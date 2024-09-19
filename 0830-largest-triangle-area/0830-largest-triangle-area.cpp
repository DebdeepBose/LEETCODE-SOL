class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& v) {
        double ans = 0;
        for (auto i : v) {
            for (auto j : v) {
                for (auto k : v) {
                    ans = max(ans, 0.5 * abs(i[0] * j[1] + j[0] * k[1] +
                                             k[0] * i[1] - j[0] * i[1] -
                                             k[0] * j[1] - i[0] * k[1]));
                }
            }
        }
        return ans;
    }
};