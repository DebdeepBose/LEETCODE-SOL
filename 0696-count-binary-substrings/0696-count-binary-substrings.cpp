class Solution {
public:
    int countBinarySubstrings(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int prevGroupSize = 0;
        int count = 0;

        while (j < n) {
            if (j == n - 1 || s[j] != s[j + 1]) {
                int curGroupSize = j - i + 1;
                count += min(prevGroupSize, curGroupSize);
                prevGroupSize = curGroupSize;
                i = j + 1;
            }

            j++;
        }
        return count;
    }
};