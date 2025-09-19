class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& v) {
        vector<int> sum;
        for (int i = 0; i < v.size(); i++) {
            int c = 0;
            for (int j = 0; j < v[0].size(); j++) {
                if (v[i][j] == 1) {
                    c++;
                }
            }
            sum.push_back(c);
        }
        int maxEl = INT_MIN;
        int maxId = -1;
        for (int i = 0; i < sum.size(); i++) {
            if (sum[i] > maxEl) {
                maxEl = sum[i];
                maxId = i;
            }
        }
        return {maxId, maxEl};
    }
};