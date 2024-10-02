class Solution {
public:
    int maxSubarraySumCircular(vector<int>& v) {
        int n = v.size();
        int minsum = INT_MAX, maxsum = INT_MIN;
        int curmx = 0;
        int curmn = 0;
        int arrsum = 0;
        
        for (int i = 0; i < n; i++) {
            curmx += v[i];
            maxsum = max(maxsum, curmx);
            curmn += v[i];
            minsum = min(minsum, curmn);
            arrsum += v[i];
            
            if (curmx < 0) {
                curmx = 0;
            }
            if (curmn > 0) {
                curmn = 0;
            }
        }
        if (arrsum == minsum) {
            return maxsum;
        }
        return max(maxsum, arrsum - minsum);
    }
};
