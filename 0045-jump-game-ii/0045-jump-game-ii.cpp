class Solution {
public:
    int jump(vector<int>& v) {
        int n = v.size();
        if (n <= 1) {
            return 0;
        }
        
        int jumps = 0;
        int lastjumpidx = 0;
        int coverage = 0;

        for (int i = 0; i < n - 1; i++) { 
            coverage = max(coverage, i + v[i]);
            if (i == lastjumpidx) {
                jumps++;
                lastjumpidx = coverage;
                if (coverage >= n - 1) {
                    return jumps;
                }
            }
        }
        return (coverage >= n - 1) ? jumps : -1;
    }
};
