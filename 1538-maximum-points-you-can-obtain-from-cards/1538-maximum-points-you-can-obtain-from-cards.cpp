class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int lsum = 0;
        for (int i = 0; i < k; i++) {
            lsum += v[i];
        }
        int maxsum = lsum;
        int r = v.size() - 1;

        for (int i = k-1; i >= 0; i--) {
            lsum -= v[i];
            lsum += v[r];
            r--;
            maxsum = max(maxsum, lsum);
        }
        
        return maxsum;
    }
};
