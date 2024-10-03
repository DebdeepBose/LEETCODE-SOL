class Solution {
public:
    bool checkInclusion(string f, string s) {
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);
        
        for (char ch : f) {
            mp1[ch - 'a']++;
        }
        int l = 0;
        int n = s.size();
        int r = 0;
        while (r < n) {
            mp2[s[r] - 'a']++;
            if (r - l + 1 == f.size()) {
                if (mp1 == mp2) {
                    return true;
                } else {
                    mp2[s[l] - 'a']--;
                    l++;
                }
            }
            r++;
        }
        return false;
    }
};
