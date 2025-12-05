class Solution {
public:
    int countPartitions(vector<int>& v) {
        int c = 0;
        int n = v.size();
        int lsum = 0;
        int rsum = accumulate(v.begin(), v.end(), 0);
        for (int i = 0; i + 1 < n; i++) {
            rsum -= v[i];
            lsum += v[i];
            if (abs(rsum - lsum) % 2 == 0) {
                c++;
            }
        }
        return c;
    }
};