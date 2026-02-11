class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }

        int i = 0;
        int j = 0;
        int c = 0;

        int prev = 0;

        while (j < n) {

            if (j + 1 == n || s[j] != s[j + 1]) {

                int cur = j - i + 1;
                c += min(prev, cur);

                prev = cur;
                i = j + 1;
            }

            j++;
        }

        return c;
    }
};