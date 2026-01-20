class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        if (n == k) {
            return s;
        }
        k %= n;
        string r;
        for (int i = 0; i < n; i++) {
            int idx = (i + k) % n;
            r += s[idx];
        }
        return r;
    }
};