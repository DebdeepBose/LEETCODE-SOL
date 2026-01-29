class Solution {
public:
    string decodeAtIndex(string s, int k) {

        int n = s.size();
        long long ans = 0;

        for (char c : s) {
            if (isdigit(c)) {
                ans *= (c - '0');
            } else {
                ans++;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if (isdigit(c)) {
                int d = c - '0';
                ans /= d;
                k %= ans;
                if (k == 0)
                    k = ans;
            } else {
                if (k == ans) {
                    return string(1, c);
                }
                ans--;
            }
        }

        return "";
    }
};
