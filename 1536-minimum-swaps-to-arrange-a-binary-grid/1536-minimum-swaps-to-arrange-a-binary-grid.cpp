class Solution {
public:
    int minSwaps(vector<vector<int>>& v) {
        int n = v.size();

        // If its a 1x 1 matrxi then no swaps would be possible hence 0;
        if (n == 1) {
            return 0;
        }
        // This stores the number of trailing zeroes in each row
        vector<int> z;

        for (int i = 0; i < n; i++) {
            int zCnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (v[i][j] != 0) {
                    break;
                }
                zCnt++;
            }
            z.push_back(zCnt);
        }

        // Now if we think about it, upper right diagonal basiaclly means we
        // need such rows that have (n-1) number of zeroes until a row with 1
        // zero so basically (n-1) 0's, (n-2)0's .... one 0.
        int swaps = 0;
        for (int i = 0; i < z.size(); i++) {
            int req0s = n - i - 1;
            int j = i;
            while (j < n && z[j] < req0s) {
                j++;
            }
            if (j == n) return -1;  // No valid row found

            // Bubble row j up to i
            while (j > i) {
                swap(z[j], z[j - 1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};