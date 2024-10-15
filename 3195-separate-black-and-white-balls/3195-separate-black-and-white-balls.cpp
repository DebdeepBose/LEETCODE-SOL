class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        if (n == 1) {
            return 0;
        }
        int l = 0, r = n - 1;
        long long steps = 0;

        while (l < r) {
            if (s[l] == '1' && s[r] == '0') {
                steps += r - l;
                l++;
                r--;
            } else if (s[r] != '0') {
                r--;
            } else if (s[l] != '1') {
                l++;
            }
        }

        return steps;
    }
};
