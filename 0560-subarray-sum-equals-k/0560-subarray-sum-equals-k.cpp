class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int n = v.size();
        int s = 0;
        int c = 0;
        int l = 0, r = 0;
        while (r < n) {
            s += v[r];
            if (s == k) {
                c++;
            } else if (s > k) {
                while (s > k) {
                    s -= v[l];
                    if (s == k) {
                        c++;
                    }
                    l++;
                }
            }
            r++;
        }
        return c;
    }
};