class Solution {
public:
    int longestPalindrome(string s) {
        int o = 0;
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
            if (mp[ch] % 2 == 1)
                o++;
            else    
                o--;
        }
        if (o > 1)
            return s.length() - o + 1;
        return s.length();
    }
};
