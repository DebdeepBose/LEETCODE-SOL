class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& v) {
        int maxidx = v[0][0];
        int maxdif = v[0][1];
        for (int i = 1; i < v.size(); i++) {
            int curdif = v[i][1] - v[i - 1][1];
            if (curdif > maxdif) {
                maxdif = curdif;
                maxidx = v[i][0];
            } else if (curdif == maxdif) {
                maxidx = min(maxidx, v[i][0]);
            }
        }
        return maxidx;
    }
};