class Solution {
public:
    int dominantIndices(vector<int>& v) {
        int n = v.size();
        vector<double> avg(n);
        vector<int> pref(n);

        pref[n - 1] = v[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            pref[i] = pref[i + 1] + v[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            avg[i] = pref[i + 1] / ((n - i - 1) * 1.0);
        }

        int c = 0;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > avg[i]) {
                c++;
            }
        }
        return c;
    }
};