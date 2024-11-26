class Solution {
public:
    bool ispali(string s, int l, int r) {
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n - 1;
        
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                if (ispali(s, l + 1, r)) {
                    return true;
                }
                if (ispali(s, l, r - 1)) {
                    return true;
                }
                return false;
            }
        }
        return true;
    }
};
