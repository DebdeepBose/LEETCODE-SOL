class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> mpp, mp;
        int l = 0, r = 0, n = s.size();
        
        for (auto e : p) {
            mpp[e]++;
        }
        
        while (r < n) {
            mp[s[r]]++;
            if (r - l + 1 > p.size()) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
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
