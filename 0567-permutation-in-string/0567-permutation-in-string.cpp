class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mpp;
        unordered_map<char, int> mp;
        for (auto e : s1) {
            mpp[e]++;
        }

        int l = 0;
        int r = 0;
        int n = s2.size();

        while (r < n) {
            mp[s2[r]]++;

            if (r - l + 1 == s1.size()) {
                if (mp == mpp) {
                    return true;
                }
                mp[s2[l]]--;
                if (mp[s2[l]] == 0) {
                    mp.erase(s2[l]);
                }
                l++;
            }
            r++;
        }

        return false;
    }
};
