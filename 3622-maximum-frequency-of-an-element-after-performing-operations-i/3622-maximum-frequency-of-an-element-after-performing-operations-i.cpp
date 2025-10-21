class Solution {
public:
    int maxFrequency(vector<int>& v, int k, int op) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (auto e : v) {
            mini = min(mini, e);
            maxi = max(maxi, e);
        }

        vector<int> freq(maxi + 1);
        for (auto e : v) {
            freq[e]++;
        }

        int n = v.size();

        for (int i = 1; i <= maxi; i++) {
            freq[i] += freq[i - 1];
        }

        int ans = 0;
        for (int curr = mini; curr <= maxi; curr++) {
            int l = max(mini, curr - k);
            int r = min(maxi, curr + k);

            int f = freq[curr] - freq[curr - 1];

            int ex = min(op, freq[r] - freq[l - 1] - f);

            ans = max(ans, f + ex);
        }
        return ans;
    }
};
