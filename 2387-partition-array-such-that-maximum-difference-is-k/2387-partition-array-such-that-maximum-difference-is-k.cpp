class Solution {
public:
    int partitionArray(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int n = v.size();
        if (n == 1 || n == 0) {
            return n;
        }

        int mini = v[0];
        int parts = 1;
        for (int i = 1; i < n; i++) {
            if (v[i] - mini > k) {
                parts++;
                mini = v[i];
            }
        }
        return parts;
    }
};