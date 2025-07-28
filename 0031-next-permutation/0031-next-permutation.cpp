class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int dipIdx = -1;
        int n = v.size();
        if (n == 1) {
            return;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] < v[i + 1]) {
                dipIdx = i;
                break;
            }
        }
        if (dipIdx == -1) {
            reverse(v.begin(), v.end());
            return;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] > v[dipIdx]) {
                swap(v[i], v[dipIdx]);
                break;
            }
        }
        reverse(v.begin() + dipIdx + 1, v.end());
    }
};