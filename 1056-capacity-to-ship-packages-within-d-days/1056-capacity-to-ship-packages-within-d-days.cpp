class Solution {
public:
    int check(vector<int>& weights, int n, int mid) {
        int sum = 0;

        // If we enter this function we are guaranteed to take at least 1 day
        int dayCount = 1;

        for (int i = 0; i < n; i++) {
            if (sum + weights[i] <= mid) {
                sum += weights[i];
            } else {

                // We increase dayCount and reset sum to the current 'i' weight
                dayCount++;
                sum = weights[i];
            }
        }
        return dayCount;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        /*The heaviest package must be carried by the ship, it could be one or
         more days but the ship needs to have a capacity to carry the heaviest
         load so we set low at max_element */
        int low = *max_element(weights.begin(), weights.end());

        /*Maybe the ship can carry all the packages in 1 day itself, hence high
         is the sum of all the load*/
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int ndays = check(weights, n, mid);
            if (ndays <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
