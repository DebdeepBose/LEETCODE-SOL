class Solution {
public:
    int calculate(string s) {
        int total = 0;
        int sign = 1;
        stack<int> signs;
        signs.push(1);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == ' ') {
                continue;
            }

            if (c == '+') {
                sign = signs.top();
            } else if (c == '-') {
                sign = -signs.top();
            } else if (isdigit(c)) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                total += sign * num;
                i--;
            } else if (c == '(') {
                signs.push(sign);
            } else if (c == ')') {
                signs.pop();
            }
        }

        return total;
    }
};
