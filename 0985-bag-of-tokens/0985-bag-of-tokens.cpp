class Solution {
public:
    int bagOfTokensScore(vector<int>& v, int p) {
        int n = v.size();
        if (n == 0) {
            return 0;
        }
        sort(v.begin(), v.end());
        int l = 0;
        int r = n - 1;
        int score = 0;
        int maxScore = 0;
        while (l <= r) {
            if (p >= v[l]) {
                p -= v[l];
                score++;
                maxScore = max(maxScore, score);
                l++;
            } else if (score > 0) {
                p += v[r];
                score--;
                r--;
            } else {
                break;
            }
        }
        return maxScore;
    }
};
