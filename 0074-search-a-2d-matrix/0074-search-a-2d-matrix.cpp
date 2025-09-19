class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int k) {
        int m = v.size();
        int n = v[0].size();
        for (int i = 0; i < m; i++) {
            if (v[i][n - 1] < k) {
                continue;
            }
            if (v[i][n - 1] == k) {
                return true;
            }
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (v[i][mid] == k) {
                    return true;
                } else if (v[i][mid] < k) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            break;
        }
        return false;
    }
};
