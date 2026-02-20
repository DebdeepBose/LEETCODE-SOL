class Solution {
public:
    int findWinningPlayer(vector<int>& v, int k) {
        int n = v.size();
        int prevMax = max(v[0], v[1]);
        int prevMaxIdx = v[0] > v[1] ? 0 : 1;
        int c = 1;
        if (c == k) {
            return prevMaxIdx;
        }
        for (int i = 2; i < n; i++) {
            if (v[i] > prevMax) {
                prevMax = v[i];
                prevMaxIdx = i;
                c = 1;
            } else {
                c++;
                if (c == k) {
                    return prevMaxIdx;
                }
            }
        }
        return prevMaxIdx;
    }
};