class Solution {
public:
    bool valid(vector<int>& nums, int n, int mid, int k) {
        int sum = 0, split = 1;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] <= mid) {
                sum += nums[i];
            } else {
                split++;
                sum = nums[i];
                if (split > k) {
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (valid(nums, n, mid, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};