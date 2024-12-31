class Solution {
public:
    int minimumOperations(vector<vector<int>>& v) {
        int c = 0;
        vector<int> v2 = v[0];
        for (int i = 1; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j] <= v2[j]) {
                    c += (v2[j] + 1) - v[i][j];
                    v[i][j] = v2[j] + 1;
                }
            }
            v2 = v[i];
        }
        return c;
    }
};