class Solution {
public:
    bool canJump(vector<int>& v) {
        int n = v.size();
        int fpos = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] + i >= fpos) {
                fpos = i;
            }
        }
        return fpos == 0;
    }
};