class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int idx = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (i < 2 || v[i] > v[idx - 2]) {
                v[idx] = v[i];
                idx++;
            }
        }
        return idx;
    }
};
