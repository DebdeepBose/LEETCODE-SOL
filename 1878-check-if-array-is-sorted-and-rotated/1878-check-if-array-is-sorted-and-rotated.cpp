class Solution {
public:
    bool check(vector<int>& v) {
        int n = v.size();
        if (n == 0 || n == 1) {
            return true;
        }

        int dip = 0;

        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                dip++;
            }
        }

        if (v.back() > v.front()) {
            dip++;
        }
        return dip <= 1;
    }
};