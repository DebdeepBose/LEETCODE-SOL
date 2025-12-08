class Solution {
public:
    double minimumAverage(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        double mini = DBL_MAX;

        for (int i = 0; i < n / 2; i++) {
            double avg = (v[i] + v[n - 1 - i]) / 2.0;
            mini = min(mini, avg);
        }

        return mini;
    }
};
