class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v[0].size(); j++) {
                swap(v[i][j], v[j][i]);
            }
        }
        for (int i = 0; i < v.size(); i++) {
            reverse(v[i].begin(), v[i].end());
        }
    }
};