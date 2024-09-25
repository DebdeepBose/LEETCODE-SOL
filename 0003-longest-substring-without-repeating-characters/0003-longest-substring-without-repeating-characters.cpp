class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            vector<int> mp(256, 0);
            int currlen = 0;

            for (int j = i; j < n; j++) {
                if (mp[s[j]] == 0) {
                    currlen++;
                    mp[s[j]]++;
                } else {
                    break;
                }
            }

            maxlen = max(maxlen, currlen);
        }

        return maxlen;
    }
};