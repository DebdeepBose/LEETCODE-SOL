class Solution {
public:
    int countSubarrays(vector<int>& v) {
        int n = v.size();
        int l = 0;
        int r = 2;
        int c = 0;
        while (r < n) {
            if (v[l + 1] % 2 == 0 && v[l] + v[r] == (v[l + 1] / 2)) {
                c++;
            }
            r++;
            l++;
        }
        return c;
    }
};