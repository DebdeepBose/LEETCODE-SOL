class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int n = v.size();
        for (int i = 0; i < n; i++) {
            while (v[i] > 0 && v[i] <= n && v[v[i] - 1] != v[i]) {
                swap(v[i], v[v[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (v[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};