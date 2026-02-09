class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int m = v.size();
        if (n == 0) {
            return true;
        }
        if (m == 1) {
            if (n > 1) {
                return false;
            } else {
                if (n == 1) {
                    if (v[0] == 0) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    return true;
                }
            }
        }
        vector<bool> mark(m);
        for (int i = 0; i < m; i++) {
            if (i == 0) {
                if (v[i] == 0 && v[i + 1] == 0) {
                    v[i] = 1;
                    n--;
                }
            }
            if (i == m - 1) {
                if (v[i] == 0 && v[i - 1] == 0) {
                    v[i] = 1;
                    n--;
                }
            }
            if ((i > 0 && i < m - 1) && v[i] == 0 && v[i + 1] == 0 &&
                v[i - 1] == 0) {
                v[i] = 1;
                n--;
            }
            if (n == 0) {
                return true;
            }
        }
        return false;
    }
};