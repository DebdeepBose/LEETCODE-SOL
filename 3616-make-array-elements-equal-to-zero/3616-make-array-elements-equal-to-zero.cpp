class Solution {
public:
    bool isvalid(int i, int way, vector<int>& v, int n) {
        vector<int> tmp = v;
        bool lft;
        if (way == -1) {
            lft = true;
        } else {
            lft = false;
        }
        while (i >= 0 && i < n) {
            if (tmp[i] == 0) {
                if (lft) {
                    i -= 1;
                } else {
                    i += 1;
                }
            } else {
                tmp[i]--;
                lft = !lft;
                if (lft) {
                    i -= 1;
                } else {
                    i += 1;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (tmp[j] != 0) {
                return false;
            }
        }
        return true;
    }

    int countValidSelections(vector<int>& v) {
        int n = v.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                if (isvalid(i, -1, v, n)) {
                    c++;
                }
                if (isvalid(i, 1, v, n)) {
                    c++;
                }
            }
        }
        return c;
    }
};
