class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& v) {
        int maxEl = INT_MIN;
        int maxId = -1;
        for (int i = 0; i < v.size(); i++) {
            int c = 0;
            for (int j = 0; j < v[0].size(); j++) {
                if (v[i][j] == 1) {
                    c++;
                }
            }
            if (c > maxEl) {
                maxEl = c;
                maxId = i;
            }
        }

        return {maxId, maxEl};
    }
};