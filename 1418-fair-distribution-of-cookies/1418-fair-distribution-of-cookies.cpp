class Solution {
public:
    int distributeCookies(vector<int>& v, int k) {

        int maxFairness = INT_MAX;
        vector<int> tmpSubsets(k);
        backTrack(v, k, maxFairness, 0, tmpSubsets);

        return maxFairness;
    }
    void backTrack(vector<int>& v, int k, int& maxFairness, int idx,
                   vector<int>& tmpSubsets) {

        if (idx == v.size()) {
            int maxi = INT_MIN;
            for (int i = 0; i < k; i++) {
                maxi = max(maxi, tmpSubsets[i]);
            }
            maxFairness = min(maxFairness, maxi);
            return;
        }

        for (int i = 0; i < k; i++) {
            tmpSubsets[i] += v[idx];
            backTrack(v, k, maxFairness, idx + 1, tmpSubsets);
            tmpSubsets[i] -= v[idx];
        }
    }
};