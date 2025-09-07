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

        /* Actually i was tryin to check if m * k > n, but well integer overflow
         * strikes again and i had to resort to stone age techniques */
        if (m > n / k) {
            return -1;
        }

        int low = INT_MAX;
        int high = INT_MIN;

        for (int i = 0; i < n; i++) {
            low = min(bloomDay[i], low);
            high = max(bloomDay[i], high);
        }

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