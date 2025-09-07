class Solution {
public:
    bool check(vector<int>& bloomDay, int n, int mid, int k, int m) {
        int flower = 0, bouquet = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) {
                flower++;
                if (flower == k) {
                    bouquet++;
                    flower = 0;
                }
            } else {
                flower = 0;
            }
        }
        return bouquet >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if (m > n / k) {
            return -1;
        }

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool f = check(bloomDay, n, mid, k, m);
            if (f) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};