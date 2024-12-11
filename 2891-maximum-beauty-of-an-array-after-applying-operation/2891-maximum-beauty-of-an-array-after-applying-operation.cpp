class Solution {
public:
    int maximumBeauty(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int beg = 0, c = 0;
        int n = v.size();
        k *= 2;
        for (int i = 0; i < n; i++) {
            while (v[i] - v[beg] > k) {
                beg++;
            }
            int range = i - beg;
            c = max(c, range + 1);
        }
        return c;
    }
};
