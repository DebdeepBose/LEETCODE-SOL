class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        string temp;
        int digit;
        while(n > 2) {
            temp = "";
            for(int i = 0; i < n - 1; i++) {
                digit = (s[i] - '0' + s[i+1] - '0') % 10;
                temp += digit + '0';
            }
            s = temp;
            n = s.size();
        }
        return s[0] == s[1];
    }
};
