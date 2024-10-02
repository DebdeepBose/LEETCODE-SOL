class Solution {
public:
    double findMaxAverage(vector<int>& v, int k) {
        int l = 0;
        int r = 0;
        int n = v.size();
        double s = 0;
        double avg, maxavg = -DBL_MAX;
        while (r < n) {
            s += v[r];
            if (r - l + 1 == k) {
                avg = s / k;
                maxavg = max(maxavg, avg);
                s -= v[l];
                l++;
            }
            r++;
        }
        return maxavg;
    }
};