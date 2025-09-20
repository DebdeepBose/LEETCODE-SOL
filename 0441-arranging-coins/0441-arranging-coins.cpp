class Solution {
public:
    int arrangeCoins(int n) {

        int low = 0;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long sum = (long long)mid * (mid + 1) / 2;
            if (n == sum) {
                return mid;
            } else if (n < sum) {
                high = mid - 1;
            } else if (n > sum) {
                low = mid + 1;
            }
        }
        return high;
    }
};