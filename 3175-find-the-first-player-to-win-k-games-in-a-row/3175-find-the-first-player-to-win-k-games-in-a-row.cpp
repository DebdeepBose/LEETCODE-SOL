class Solution {
public:
    int findWinningPlayer(vector<int>& v, int k) {
        int n = v.size();
        int curMax = max(v[0], v[1]);
        int curMaxIdx = v[0] > v[1] ? 0 : 1;
        int c = 1;
        if (c == k) {
            return curMaxIdx;
        }
        for (int i = 2; i < n; i++) {
            if (v[i] > curMax) {
                curMax = v[i];
                curMaxIdx = i;
                c = 1;
            } else {
                c++;
                if (c == k) {
                    return curMaxIdx;
                }
            }
        }
        return curMaxIdx;
    }
};