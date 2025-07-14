class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n = v.size();
        int z = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] != 0) {
                v[z] = v[i];
                z++;
            }
        }
        for (int i = z; i < n; i++) {
            v[i] = 0;
        }
    }
};