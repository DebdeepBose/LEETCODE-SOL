class Solution {
public:
    vector<int> divisibilityArray(string s, int m) {
        vector<int> div(s.size(), 0);
        long long num = 0;

        for (int i = 0; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');  // Build the number incrementally
            num %= m;  // Take modulo m at each step to avoid large numbers
            if (num == 0) {
                div[i] = 1;
            }
        }

        return div;
    }
};
