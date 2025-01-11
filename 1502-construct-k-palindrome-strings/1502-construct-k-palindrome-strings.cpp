class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if (n < k) {
            return false;
        }
        if (n == k) {
            return true;
        }
        sort(s.begin(), s.end());
        int o = 0;

        for (int i = 0; i < n;) {
            char cur = s[i];
            int c = 0;
            while (i < s.length() && s[i] == cur) {
                c++;
                i++;
            }
            if (c % 2 != 0) {
                o++;
            }
        }

        return o <= k;
    }
};