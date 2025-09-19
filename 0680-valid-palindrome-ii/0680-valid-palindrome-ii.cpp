class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                // mismatch → try skipping i or skipping j
                int i1 = i + 1, j1 = j;
                int i2 = i, j2 = j - 1;

                bool skipLeft = true, skipRight = true;

                while (i1 < j1) {
                    if (s[i1] != s[j1]) {
                        skipLeft = false;
                        break;
                    }
                    i1++;
                    j1--;
                }

                while (i2 < j2) {
                    if (s[i2] != s[j2]) {
                        skipRight = false;
                        break;
                    }
                    i2++;
                    j2--;
                }

                return skipLeft || skipRight;
            }
            i++;
            j--;
        }
        return true;
    }
};
