class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& f, int st, int k) {
        int l = 0, n = f.size(), s = 0, mx = 0;
        for (int r = 0; r < n; r++) {
            s += f[r][1];
            while (l <= r && d(f[l][0], f[r][0], st) > k) {
                s -= f[l][1];
                l++;
            }
            mx = max(mx, s);
        }
        return mx;
    }

    int d(int l, int r, int st) {
        return min(abs(st - l) + (r - l), abs(st - r) + (r - l));
    }
};
