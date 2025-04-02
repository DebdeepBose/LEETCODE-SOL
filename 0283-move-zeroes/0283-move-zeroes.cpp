class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n = v.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] != 0) {
                v[j] = v[i];
                j++;
            }
        }
        for (int i = j; i < n; i++) {
            v[i] = 0;
        }
    }
};