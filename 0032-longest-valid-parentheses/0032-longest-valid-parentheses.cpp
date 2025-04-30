class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int maxlen = 0;
        for (auto c : s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                right++;
            }
            if (left == right) {
                maxlen = max(maxlen, left + right);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }
        left = 0;
        right = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else if (s[i] == ')') {
                right++;
            }
            if (left == right) {
                maxlen = max(maxlen, left + right);
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }
        return maxlen;
    }
};