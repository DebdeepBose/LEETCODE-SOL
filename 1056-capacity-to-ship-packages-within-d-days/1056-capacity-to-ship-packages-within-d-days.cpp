class Solution {
public:
    int check(vector<int>& weights, int n, int mid) {
        int sum = 0;
        int d = 1; // start with 1 day (at least one day needed)
        for (int i = 0; i < n; i++) {
            if (sum + weights[i] <= mid) {
                sum += weights[i];
            } else {
                d++;
                sum = weights[i]; // reset to current weight
            }
        }
        return d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        // low must be at least the heaviest weight
        int low = *max_element(weights.begin(), weights.end());
        // high is sum of all weights
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int ndays = check(weights, n, mid);
            if (ndays <= days) {
                high = mid - 1;  // try smaller capacity
            } else {
                low = mid + 1;   // need larger capacity
            }
        }
        return low;
    }
};
