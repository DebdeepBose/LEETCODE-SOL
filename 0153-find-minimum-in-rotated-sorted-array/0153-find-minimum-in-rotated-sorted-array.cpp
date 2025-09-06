class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();

        // If array is empty, return 0
        if (n == 0) {
            return 0;
        }

        // Basic range set
        int low = 0;
        int high = n - 1;

        /*In this case the array is normal/unsorted/sorted n times so just
         * return the lowest aka first element*/
        if (nums[low] <= nums[high]) {
            return nums[low];
        }

        int ans = INT_MAX; // We using min dats why
        while (low <= high) {

            // Basic BS
            int mid = low + (high - low) / 2;

            /*This means left part is sorted and the first element is by default
            the lowest, thats a no brainer, also we do low = mid + 1 to
            eliminate that subarray since we already got our lowest element*/
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;

            /*Same but for right side*/
            } else if (nums[mid] <= nums[high]) {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};