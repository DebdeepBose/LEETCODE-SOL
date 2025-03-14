class Solution {
public:
    long long checkdiv(int mid, vector<int>& v) {
        long long s = 0;
        for (auto e : v) {
            s += e / mid;
        }
        return s;
    }

    int maximumCandies(vector<int>& v, long long k) {
        long long totalc = 0, maxc = LLONG_MIN;
        for (int i = 0; i < v.size(); i++) {
            totalc += v[i];
            maxc = max((int)maxc, v[i]);
        }
        if (k > totalc) {
            return 0;
        }

        int l = 1, r = maxc;
        long long ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long avail = checkdiv(mid, v);

            if (avail >= k) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
