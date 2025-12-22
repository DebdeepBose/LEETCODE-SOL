class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cn = 0;
        for (auto e : s) {
            if (e == c) {
                cn++;
            }
        }
        return (long long)cn * (cn + 1) / 2;
    }
};