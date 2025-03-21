class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i == n) {
            return 0;
        }

        int ans = 0;
        bool neg = s[i] == '-';
        bool pos = s[i] == '+';

        if (neg || pos) {
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return neg ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit;
            i++;
        }

        return neg ? -ans : ans;
    }
};