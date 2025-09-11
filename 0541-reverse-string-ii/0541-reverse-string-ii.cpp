class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        int n = s.size();
        if (n < k) {
            reverse(s.begin(), s.end());
            return s;
        }
        while (i < n) {
            if (n - i >= k) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
            i += 2 * k; 
        }
        return s;
    }
};
