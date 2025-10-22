#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int maxFrequency(vector<int>& v, int k, int op) {
        int n = v.size();
        sort(v.begin(), v.end());

        int ans = 0;
        int cnt = 0;
        int l = 0;
        int r = 0;

        for (int i = 0; i < n; i++) {
            int curr = v[i];
            int L = max(1, (curr - k));
            int R = min(v.back(), (curr + k));

            int f = 1;
            int j = (i + 1);
            for (; (j < n) && (v[j] == curr); j++) {
                f++;
            }
            i = (j - 1);

            while ((l < n) && (v[l] < L)) {
                l++;
            }

            if (r < i) {
                r = i;
            }
            while ((r + 1 < n) && (v[r + 1] <= R)) {
                r++;
            }

            cnt = (r - l + 1);
            ans = max(ans, (f + min((cnt - f), op)));
        }

        for (l = 0, r = 0; r < n; r++) {
            int curr = v[r];
            int L = max(1, (curr - 2 * k));
            while ((l < r) && (v[l] < L)) {
                l++;
            }
            ans = max(ans, min((r - l + 1), op));
        }

        return ans;
    }
};
