class Solution {
public:
    long long validSubstringCount(string s, string t) {
        vector<int> mpp(26, 0);
        for (char e : t) {
            mpp[e - 'a']++;
        }

        int l = 0, r = 0, n = s.length();
        long long ans = 0;
        vector<int> mp(26, 0);
        int req = 0, form = 0;

        for (int count : mpp) {
            if (count > 0) req++;
        }

        while (r < n) {
            mp[s[r] - 'a']++;
            if (mpp[s[r] - 'a'] > 0 && mp[s[r] - 'a'] == mpp[s[r] - 'a']) {
                form++;
            }

            while (l <= r && form == req) {
                ans += n - r;
                mp[s[l] - 'a']--;
                if (mpp[s[l] - 'a'] > 0 && mp[s[l] - 'a'] < mpp[s[l] - 'a']) {
                    form--;
                }
                l++;
            }
            r++;
        }

        return ans;
    }
};
