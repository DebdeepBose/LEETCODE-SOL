class Solution {
public:
    int maximumCount(vector<int>& v) {
        int p = 0, n = 0;
        for (auto e : v) {
            if (e > 0) {
                p++;
            } else if (e < 0) {
                n++;
            }
        }
        return max(p, n);
    }
};