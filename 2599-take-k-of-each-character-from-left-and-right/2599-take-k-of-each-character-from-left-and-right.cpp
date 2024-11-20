class Solution {
public:
    int takeCharacters(string s, int k) { 
        int n = s.length(), r = 0, ans = n, win = 0;
        unordered_map<char, int> mp;
        for (auto e : s) {
            mp[e]++;
        }
        if (mp['a'] < k || mp['b'] < k || mp['c'] < k)  
            return -1;
        for (int i = 0; i < n; i++) {
            mp[s[i]]--;
            win++;
            while (mp['a'] < k || mp['b'] < k || mp['c'] < k) {
                mp[s[r]]++; 
                win--;
                r++;
            }
            ans = min(ans, n - win);
        }
        return ans;
    }
};
