class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int k) {
        int m = v.size();
        int n = v[0].size();
        
        int top = 0;
        int bottom = m - 1;
        int targetRow = -1;
        
        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;
            if (v[mid][n - 1] == k) {
                return true;
            } else if (v[mid][n - 1] > k) {
                targetRow = mid;
                bottom = mid - 1;
            } else {
                top = mid + 1;
            }
        }
        
        if (targetRow == -1) {
            return false;
        }
        
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[targetRow][mid] == k) {
                return true;
            } else if (v[targetRow][mid] < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
