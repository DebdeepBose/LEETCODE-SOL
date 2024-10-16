class Solution {
public:
    int calc(vector<int> v, int mid, int n) {
        int c = 1;
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (s + v[i] <= mid) {
                s += v[i];
            } else {
                c++;
                s = v[i];
                if (s > mid) {
                    return INT_MAX;
                }
            }
        }
        return c;
    }
    int splitArray(vector<int>& v, int k) {
        int n = v.size();
        if (k > n) {
            return -1;
        }
        int low = *min_element(v.begin(), v.end());
        int high = accumulate(v.begin(), v.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int numStud = calc(v, mid, n);
            if (numStud > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};