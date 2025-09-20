class Solution {
public:
    int arrangeCoins(int n) {

        // Basic search space
        int low = 0;
        int high = n;

        while (low <= high) {
            /* Aight so here we find mid and try to compute the sum from
            1 -> mid using formula if n == sum that means 'mid' is the number of
            complete rows*/
            int mid = low + (high - low) / 2;
            long long sum = (long long)mid * (mid + 1) / 2;
            if (n == sum) {
                return mid;

                /* if n < sum that means mid is quite a large number which
                 * results in a larger sum, in order to reduce sum we gotta
                 * reduce mid so high = mid - 1*/
            } else if (n < sum) {
                high = mid - 1;

                // Converesely if n > sum we do low = mid + 1;
            } else if (n > sum) {
                low = mid + 1;
            }
        }

        // High points to our answer in case mid couldnt find it
        return high;
    }
};