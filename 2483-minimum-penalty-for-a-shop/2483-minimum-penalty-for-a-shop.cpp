class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<int> pre(n);

        // Build prefix sum
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (s[i] == 'Y') {
                    pre[i] = -1;
                }
                if (s[i] == 'N') {
                    pre[i] = 1;
                }
            } else {
                if (s[i] == 'Y') {
                    pre[i] = pre[i - 1] - 1;
                }
                if (s[i] == 'N') {
                    pre[i] = pre[i - 1] + 1;
                }
            }
        }

        int minVal = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (pre[i] < minVal) {
                minVal = pre[i];
                ans = i + 1;
            }
        }

        return ans;
    }
};
