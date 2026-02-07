class Solution {
public:
    string maximumBinaryString(string s) {
        int n = s.size();
        int fz = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                fz = i;
                break;
            }
        }
        if (fz == -1) {
            return s;
        }
        int z = 0, o = 0;
        for (int i = fz; i < n; i++) {
            if (s[i] == '0') {
                z++;
            } else {
                o++;
            }
        }
        int i = fz;
        while (z > 1) {
            s[i++] = '1';
            z--;
        }
        s[i++] = '0';
        while (o > 0) {
            s[i++] = '1';
            o--;
        }
        return s;
    }
};