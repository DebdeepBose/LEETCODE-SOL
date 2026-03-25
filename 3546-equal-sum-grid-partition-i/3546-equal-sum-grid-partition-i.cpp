class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> rowSum(m), colSum(n);
        for (int i = 0; i < m; i++) {
            rowSum[i] = accumulate(grid[i].begin(), grid[i].end(), 0LL);
        }
        for (int j = 0; j < n; j++) {
            long long i = 0;
            long long sum = 0;
            while (i < m) {
                sum += grid[i++][j];
            }
            colSum[j] = sum;
        }

        // Prefix sum for filling row and col
        vector<long long> prefRowSum(m), prefColSum(n);
        prefRowSum[0] = rowSum[0];
        prefColSum[0] = colSum[0];

        // Suffix sum for filling row/col backwards
        vector<long long> sufRowSum(m), sufColSum(n);
        sufRowSum.back() = rowSum.back();
        sufColSum.back() = colSum.back();

        if (m > 1) {
            for (int i = 1; i < m; i++) {
                prefRowSum[i] = prefRowSum[i - 1] + rowSum[i];
            }
            for (int i = m - 2; i >= 0; i--) {
                sufRowSum[i] = sufRowSum[i + 1] + rowSum[i];
            }
        }
        if (n > 1) {
            for (int i = 1; i < n; i++) {
                prefColSum[i] = prefColSum[i - 1] + colSum[i];
            }
            for (int i = n - 2; i >= 0; i--) {
                sufColSum[i] = sufColSum[i + 1] + colSum[i];
            }
        }

        // Placing cuts
        if (m > 1) {
            for (int i = 0; i < m - 1; i++) {
                if (prefRowSum[i] == sufRowSum[i + 1]) {
                    return true;
                }
            }
        }
        if (n > 1) {
            for (int i = 0; i < n - 1; i++) {
                if (prefColSum[i] == sufColSum[i + 1]) {
                    return true;
                }
            }
        }

        // If cuts didnt work
        return false;
    }
};