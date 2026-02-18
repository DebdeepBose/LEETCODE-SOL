class Solution {
private:
    string getBin(int n) {
        if (n == 0) {
            return "0";
        }
        string ans = "";
        while (n > 0) {
            ans += (n & 1) + '0';
            n >>= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool checkAlt(string s, int i, char prev) {
        if (i == s.size()) {
            return true;
        }

        if (s[i] != prev) {
            prev = s[i];
            return checkAlt(s, i + 1, prev);
        }

        return false;
    }

public:
    bool hasAlternatingBits(int n) {
       
        string s = getBin(n);

        return checkAlt(s, 1, s[0]);
    }
};