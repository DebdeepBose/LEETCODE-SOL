class Solution {
public:
    long long countSubarrays(vector<int>& v, int minK, int maxK) {
        long res = 0, jbad = -1, jmin = -1, jmax = -1, n = v.size();
        for (int i = 0; i < n; i++) {
            if (v[i] < minK || v[i] > maxK) {
                jbad = i;
            }
            if (v[i] == minK) {
                jmin = i;
            }
            if (v[i] == maxK) {
                jmax = i;
            }
            res += max(0L, min(jmin, jmax) - jbad);
        }
        return res;
    }
};