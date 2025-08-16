class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n == 0) {
            return 0;
        }
        string sz = to_string(n);
        int ssz = sz.size();
        int cut = ssz;
        for (int i = ssz - 1; i > 0; i--) {
            if (sz[i - 1] > sz[i]) {
                sz[i - 1]--;
                cut = i;
            }
        }
        for (int i = cut; i < ssz; i++) {
            sz[i] = '9';
        }
        return stoi(sz);
    }
};
