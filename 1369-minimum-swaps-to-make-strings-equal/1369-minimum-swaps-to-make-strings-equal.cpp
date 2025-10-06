class Solution {
public:
    int minimumSwap(string f, string s) {
  
        int m = f.size();

        int fs = 0;
        int ss = 0;

        for (int i = 0; i < m; i++) {
            if (f[i] == 'x' && s[i] == 'y') {
                fs++;
            }
            if (f[i] == 'y' && s[i] == 'x') {
                ss++;
            }
        }
        if ((fs + ss) % 2 == 1) {
            return -1;
        }
        return fs / 2 + ss / 2 + (fs % 2) * 2;
    }
};