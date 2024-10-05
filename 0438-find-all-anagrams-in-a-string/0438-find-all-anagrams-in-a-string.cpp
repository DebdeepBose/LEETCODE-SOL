class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> mpp(26, 0), mp(26, 0);
        int l = 0, r = 0, n = s.size();
        
        for (char e : p) {
            mpp[e - 'a']++;
        }
        
        while (r < n) {
            mp[s[r] - 'a']++;
            if (r - l + 1 > p.size()) {
                mp[s[l] - 'a']--;
                l++;
            }
            if (mp == mpp) {
                ans.push_back(l);
            }
            r++;
        }
        
        return ans;
    }
};
