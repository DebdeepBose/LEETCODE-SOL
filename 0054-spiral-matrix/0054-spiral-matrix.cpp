class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        if (v.empty()) {
            return {};
        }
        vector<int> ans;
        int n = v.size(), m = v[0].size();
        int top = 0, left = 0, bottom = n - 1, right = m - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                ans.push_back(v[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                ans.push_back(v[i][right]);
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(v[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(v[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};