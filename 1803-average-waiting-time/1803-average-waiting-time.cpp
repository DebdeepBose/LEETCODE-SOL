class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& v) {
        int n = v.size();
        double totalTime = 0;
        int start = v[0][0];
        int finish;
        for (int i = 0; i < n; i++) {
            if (start >= v[i][0]) {
                finish = start + v[i][1];
            } else {
                finish = v[i][0] + v[i][1];
            }
            int diff = finish - v[i][0];
            totalTime += diff;
            start = finish;
        }
        return totalTime / n;
    }
};