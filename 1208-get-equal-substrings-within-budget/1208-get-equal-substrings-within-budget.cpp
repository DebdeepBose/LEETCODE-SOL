class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        if (maxCost == 0) {
            if (s == t) {
                return s.size();
            }
            return 1;
        }

        int n = s.size();
        int i = 0;
        int j = 0;
        int maxLen = 0;
        int cost = 0;
        while (j < n) {
            cost += abs(s[j] - t[j]);
            while (cost > maxCost) {
                cost -= abs(s[i] - t[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};