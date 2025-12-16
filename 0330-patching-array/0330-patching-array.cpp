class Solution {
public:
    int minPatches(vector<int>& v, int n) {
        long long target = 1;
        int p = 0;
        int m = v.size();
        int i = 0;
        while (target <= n) {
            if (i < m && v[i] <= target) {
                target += v[i];
                i++;
            } else {
                target += target;
                p++;
            }
        }
        return p;
    }
};