class Solution {
public:
    bool checkInclusion(string f, string s) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (char ch : f) {
            mp1[ch]++;
        }
        int l = 0;
        int r = 0;
        int n = s.size();
        while (r < n) {
            mp2[s[r]]++;
            if (r - l + 1 == f.size()) {
                if (mp1 == mp2) {
                    return true;
                } else {
                    mp2[s[l]]--;
                    if (mp2[s[l]] == 0) {
                        mp2.erase(s[l]);
                    }
                    l++;
                }
            }
            r++;
        }
        return false;
    }
};