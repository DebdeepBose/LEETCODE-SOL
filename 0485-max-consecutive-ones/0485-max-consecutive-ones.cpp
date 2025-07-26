class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int c = 0;
        int maxc = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 1) {
                c++;
            } else {
                c = 0;
            }
            maxc = max(maxc, c);
        }
        return maxc;
    }
};