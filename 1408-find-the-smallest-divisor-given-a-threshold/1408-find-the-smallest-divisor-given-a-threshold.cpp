class Solution {
public:
    double check(vector<int>& nums, int n, int mid) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)nums[i] / (double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            double tsum = check(nums, n, mid);
            if (tsum <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};