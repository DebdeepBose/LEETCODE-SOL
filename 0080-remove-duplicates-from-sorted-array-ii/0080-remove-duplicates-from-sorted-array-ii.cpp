class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size();
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (i < 2 || v[idx - 2] != v[i]) {
                v[idx] = v[i];
                idx++;
            }
        }
        return idx;
    }
};