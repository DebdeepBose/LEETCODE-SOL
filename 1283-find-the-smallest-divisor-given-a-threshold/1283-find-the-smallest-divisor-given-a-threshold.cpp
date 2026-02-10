class Solution {
public:
    int check(int mid, vector<int>& v, int n) {
        double p = 0;
        for (int i = 0; i < n; i++) {
            p += ceil((double)v[i] / (double)mid);
        }
        return (int)p;
    }
    int smallestDivisor(vector<int>& v, int k) {
        int n = v.size();

        int low = 1;
        int high = *max_element(v.begin(), v.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, v, n) <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};