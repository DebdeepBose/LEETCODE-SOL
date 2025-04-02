class Solution {
public:
    void nextPermutation(vector<int>& v) {

        int n = v.size();
        int idx = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] < v[i + 1]) {
                idx = v[i];
                break;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (v[i] > v[idx]) {
                swap(v[i], v[idx]);
                break;
            }
        }

        reverse(v.begin() + idx + 1, v.end());
    }
};