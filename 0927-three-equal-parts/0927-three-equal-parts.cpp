class Solution {
public:
    vector<int> threeEqualParts(vector<int>& v) {
        int n = v.size();
        int ones = count(v.begin(), v.end(), 1);

        if (ones % 3 != 0) {
            return {-1, -1};
        }
        if (ones == 0) {
            return {0, n - 1};
        }

        int onePartVal = ones / 3;
        int i1 = -1, i2 = -1, i3 = -1;
        int c = 0;

        for (int i = 0; i < n; i++) {
            if (v[i] == 1) {
                c++;
                if (c == 1) {
                    i1 = i;
                } else if (c == onePartVal + 1) {
                    i2 = i;
                } else if (c == 2 * onePartVal + 1) {
                    i3 = i;
                }
            }
        }

        while (i3 < n) {
            if (v[i1] != v[i2] || v[i2] != v[i3]) {
                return {-1, -1};
            }
            i1++;
            i2++;
            i3++;
        }

        return {i1 - 1, i2};
    }
};
