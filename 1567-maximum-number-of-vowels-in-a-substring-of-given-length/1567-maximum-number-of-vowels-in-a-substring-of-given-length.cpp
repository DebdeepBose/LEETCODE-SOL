class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxv = 0;
        unordered_map<char, int> mp;
        
        while (r < n) {
            mp[s[r]]++;
            if (r - l + 1 == k) {
                int v = mp['a'] + mp['e'] + mp['i'] + mp['o'] + mp['u'];
                maxv = max(maxv, v);
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return maxv;
    }
};
