class Solution {
private:
    string toBin(int n) {
        string r = "";
        while (n > 0) {
            r += (n & 1) + '0';
            n >>= 1;
        }
        reverse(r.begin(), r.end());
        return r;
    }

public:
    int binaryGap(int n) {
        string s = toBin(n);
        int maxGap = 0;
        int i = 0;
        int j = 0;
        int len = s.size();
        while (j < len) {
            while (j < len && s[j] != '1') {
                j++;
            }
            if (s[i] == '1' && s[j] == '1') {
                maxGap = max(maxGap, j - i);
                i = j;
            }
            j++;
        }
        return maxGap;
    }
};