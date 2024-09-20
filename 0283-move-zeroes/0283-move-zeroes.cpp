class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int movidx = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != 0) {
                v[movidx] = v[i];
                movidx++;
            }
        }
        while (movidx < v.size()) {
            v[movidx] = 0;
            movidx++;
        }
    }
};