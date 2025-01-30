class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (n == 0 || n < k) {
            return 0;
        }
        if (k <= 1) {
            return n;
        }
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        int left = 0;
        while (left < n && mp[s[left]] >= k) {
            left++;
        }
        if (left >= n - 1) {
            return left;
        }
        int l1 = longestSubstring(s.substr(0, left), k);
        while (left < n && mp[s[left]] < k) {
            left++;
        }
        int l2;
        if (left < n) {
            l2 = longestSubstring(s.substr(left), k);
        } else {
            l2 = 0;
        }
        return max(l1, l2);
    }
};
