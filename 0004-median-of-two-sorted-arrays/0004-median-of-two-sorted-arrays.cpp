class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int m = v1.size(), n = v2.size();
        int t = m + n;
        int i = 0, j = 0, c = 0;

        int i1 = t / 2;
        int i2;
        if (t % 2 == 0) {
            i2 = i1 - 1;
        } else {
            i2 = i1;
        }

        int i1el = -1, i2el = -1;

        while (i < m || j < n) {
            int val;
            if (i < m && (j >= n || v1[i] < v2[j])) {
                val = v1[i];
                i++;
            } else {
                val = v2[j];
                j++;
            }

            if (c == i2) {
                i2el = val;
            }
            if (c == i1) {
                i1el = val;
                break;
            }
            c++;
        }

        if (t % 2 == 1) {
            return i1el;
        } else {
            return (i1el + i2el) / 2.0;
        }
    }
};
