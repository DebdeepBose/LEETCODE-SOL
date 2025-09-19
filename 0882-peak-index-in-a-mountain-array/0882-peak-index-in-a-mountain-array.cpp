class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int n = v.size();
        for (int i = 1; i < n - 1; i++) {
            if (v[i] > v[i + 1] && v[i] > v[i - 1]) {
                return i;
            }
        }
        return -1;
    }
};