class Solution {
public:
    string shiftingLetters(string s, vector<int>& v) {
        int n = v.size();
        if (n == 1) {
            s[0] = (s[0] - 'a' + v[0] % 26) % 26 + 'a';
            return s;
        }
         for (int i = n - 2; i >= 0; i--) {
            v[i] = (v[i] + v[i + 1]) % 26;
        }
        for (int i = 0; i < n; i++) {
            s[i] = (s[i] - 'a' + v[i] % 26) % 26 + 'a';
        }

        return s;
    }
};