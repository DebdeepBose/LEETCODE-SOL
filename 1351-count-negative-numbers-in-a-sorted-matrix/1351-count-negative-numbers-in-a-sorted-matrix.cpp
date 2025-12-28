class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        int i = 0;
        int j = n - 1;
        int ans = 0;
        while (i < m && j >= 0) {
            if (v[i][j] < 0) {
                j--;
                if (j == -1) {
                    ans += n * (m - i);
                }
            } else {
                ans += (n - j - 1);
                i++;
            }
        }
        return ans;
    }
};