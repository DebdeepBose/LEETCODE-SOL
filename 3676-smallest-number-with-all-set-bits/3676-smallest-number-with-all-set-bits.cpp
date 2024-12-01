class Solution {
public:
    int smallestNumber(int n) {
        vector<int> v = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= n) {
                return v[i];
            }
        }
        return -1;
    }
};