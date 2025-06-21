class Solution {
public:
    int minimumDeletions(string s, int k) {
        vector<int> mp(26, 0);
        for (auto e : s) {
            mp[e - 'a']++;
        }

        int ans = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (mp[i] == 0) {
                continue;
            }
            int todel = 0;
            int ref = mp[i];
            for (int j = 0; j < 26; j++) {
                if (j == i || mp[j] == 0) {
                    continue;
                }
                if (mp[j] < ref) {
                    todel += mp[j];
                } else if (mp[j] - ref > k) {
                    todel += mp[j] - ref - k;
                }
            }
            ans = min(ans, todel);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};