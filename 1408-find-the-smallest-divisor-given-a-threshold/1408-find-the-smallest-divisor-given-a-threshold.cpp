class Solution {
public:
    double calculateSum(vector<int>& nums, int n, int divisor) {

        // Same idea as Koko problem, but instead of hours it’s sum of ceilings
        double total = 0;
        for (int i = 0; i < n; i++) {
            total += ceil((double)nums[i] / (double)divisor);
        }
        return total;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        /* We can’t take low as min_element because the divisor must be at least 1.
           Dividing by 0 makes no sense, and if we took something larger than 1
           (like min_element), we might miss valid smaller divisors (like 1). */
        int low = 1;

        /* High can safely be the maximum element of nums. Why?
           Because if you divide the largest number by itself, it contributes exactly 1,
           which is the smallest contribution possible from that element. */
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            double totalSum = calculateSum(nums, n, mid);

            if (totalSum <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
