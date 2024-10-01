class Solution {
public:
    bool isPalindrome(int x) {
        if (x >= 0) {
            string s = to_string(x);
            string r = s;
            ::reverse(s.begin(), s.end());
            if (r == s || r.size() == 0) {
                return true;
            }
        } else if (x < 0) {
            return false;
        }
        return {};
    }
};