class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto e : t) {
            mp[e]++;
        }
        
        int l = 0, r = 0, minLen = INT_MAX, start = 0, count = t.size();
        
        while (r < s.size()) {
            if (mp[s[r]] > 0) count--;
            mp[s[r]]--;
            r++;
            
            while (count == 0) {
                if (r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) count++;
                l++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
