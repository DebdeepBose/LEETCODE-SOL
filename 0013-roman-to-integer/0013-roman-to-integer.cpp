class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int x = 0;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        for (int i = 0; i < n; i++) {
            if (mp[s[i]] < mp[s[i + 1]]) {
                x -= mp[s[i]];
            } else {
                x += mp[s[i]];
            }
        }
        return x;
    }
};