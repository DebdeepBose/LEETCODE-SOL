class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) {
        int n = mat.size();

        // 0deg check
        if (mat == tar) {
            return true;
        }

        // 90deg check
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (auto& row : mat) {
            reverse(row.begin(), row.end());
        }
        if (mat == tar) {
            return true;
        }

        // 180deg check
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (auto& row : mat) {
            reverse(row.begin(), row.end());
        }
        if (mat == tar) {
            return true;
        }

        // 270deg check
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (auto& row : mat) {
            reverse(row.begin(), row.end());
        }
        if (mat == tar) {
            return true;
        }

        return false;
    }
};