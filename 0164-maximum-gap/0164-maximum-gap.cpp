class Solution {
public:
    int maximumGap(vector<int>& v) {
        long long n = v.size();
        if (n < 2) {
            return 0;
        }
        int maxi = *max_element(v.begin(), v.end());
        int mini = *min_element(v.begin(), v.end());
        vector<int> buckmax(n, INT_MIN);
        vector<int> buckmin(n, INT_MAX);
        if (maxi == mini) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            long long idx = (((v[i] - mini) * (n - 1)) / (maxi - mini));
            buckmax[idx] = max(buckmax[idx], v[i]);
            buckmin[idx] = min(buckmin[idx], v[i]);
        }
        int mxg = 0;
        int i = 0, j = 1;
        while (j < n) {
            if (buckmax[j] == INT_MIN) {
                j++;
            } else if (buckmax[i] == INT_MIN) {
                i++;
            } else {
                mxg = max(mxg, buckmin[j] - buckmax[i]);
                i++, j++;
            }
        }
        return mxg;
    }
};
