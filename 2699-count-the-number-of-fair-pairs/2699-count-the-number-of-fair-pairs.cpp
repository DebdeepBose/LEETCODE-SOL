class Solution {
public:
    long long countFairPairs(vector<int>& v, int l, int h) {
        int n = v.size();
        long long c = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < n - 1; i++) {
            int ltf = l - v[i];
            int utf = h - v[i];
            auto lb = lower_bound(v.begin() + i + 1, v.end(), ltf);
            auto ub = upper_bound(v.begin() + i + 1, v.end(), utf);
            c += abs(lb - ub);
        }
        return c;
    }
};