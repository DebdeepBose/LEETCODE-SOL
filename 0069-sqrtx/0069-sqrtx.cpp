class Solution {
public:
    int mySqrt(int x) {

        if (x == 1 || x == 0) {
            return x;
        }

        // Apart from 0 nobody has a square root as low as 0 so we can start
        // from 1
        int low = 1;
        // Thats the max high can go, exception was 1 so we put a separate edge
        // case for it
        int high = x / 2;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long squareOfMid = mid * mid;
            if (squareOfMid == x) {
                return mid;
            } else if (squareOfMid < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};