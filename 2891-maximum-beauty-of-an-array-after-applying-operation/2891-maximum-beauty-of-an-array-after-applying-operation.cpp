class Solution {
public:
    int maximumBeauty(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int beg = 0;
        int l = 0;
        int c = 0;
        int n = v.size();
        k *= 2;
        while (l < n) {
            while (v[l] - v[beg] > k) {
                beg++;
            }
            int range = l - beg;
            c = max(c, range + 1);
            l++;
        }
        return c;
    }
};
