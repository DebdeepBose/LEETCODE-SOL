class Solution {
public:
    int longestSquareStreak(vector<int>& v) {
        sort(v.rbegin(), v.rend());
        unordered_map<int, int> mp;
        for (auto e : v) {
            mp[e]++;
        }

        int len;
        int maxlen = 1;

        for (int i = 0; i < v.size(); i++) {
            len = 1;
            int curr = v[i];
            while (mp[sqrt(curr)] > 0) {
                int s = sqrt(curr);
                if (s * s == curr) {
                    len++;
                } else {
                    break;
                }
                mp[sqrt(curr)]--;
                curr = sqrt(curr);
            }
            maxlen = max(maxlen, len);
        }
        return maxlen == 1 ? -1 : maxlen;
    }
};