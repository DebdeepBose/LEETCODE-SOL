class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& v, int x, int y,
                                         int t) {
        int m = v.size();
        int n = v[0].size();

        for (int i = y; i < y + t; i++) {
            int j = x;
            int k = x + t - 1;
            while (j < k) {
                swap(v[j++][i], v[k--][i]);
            }
        }

        return v;
    }
};