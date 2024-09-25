class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int leftsum = accumulate(v.begin(), v.begin() + k, 0);
        int maxsum = leftsum;
        int right = v.size() - 1;
        for (int i = 0; i < k; i++) {
            leftsum -= v[k - i - 1];
            leftsum += v[right];
            right--;
            maxsum = max(maxsum, leftsum);
        }
        return leftsum;
    }
};