
class Solution {
public:
    long long validSubstringCount(string s, string t) {
        unordered_map<char, int> mpp;
        for (char e : t) {
            mpp[e]++;
        }
        int l = 0;
        int r = 0;
        int n = s.length();
        long long ans = 0;
        unordered_map<char, int> mp;
        int req = mpp.size();
        int form = 0;
        while (r < n) {
            mp[s[r]]++;
            if (mpp[s[r]] > 0 && mp[s[r]] == mpp[s[r]]) {
                form++;
            }
            while (l <= r && form == req) {
                ans += n - r;
                mp[s[l]]--;
                if (mpp[s[l]] > 0 && mp[s[l]] < mpp[s[l]]) {
                    form--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};
