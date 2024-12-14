class Solution {
public:
    long long continuousSubarrays(vector<int>& v) {
        int l = 0, r = 0, j = 0;
        long long c = 0;
        int n = v.size();

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                c++;
                l = v[i] - 2;
                r = v[i] + 2;
            } else if (v[i] >= l && v[i] <= r) {
                l = max(l, v[i] - 2);
                r = min(r, v[i] + 2);
                c = c + (i - j + 1);
            } else {
                j = i - 1;
                l = v[i] - 2, r = v[i] + 2;
                while (v[j] >= v[i] - 2 && v[j] <= v[i] + 2) {
                    l = max(l, v[j] - 2);
                    r = min(r, v[j] + 2);
                    j--;
                }
                j++;
                c = c + (i - j + 1);
            }
        }

        return c;
    }
};
