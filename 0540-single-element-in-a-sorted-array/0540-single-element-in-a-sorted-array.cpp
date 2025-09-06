class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Boundary checks to avoid out of bounds
            if (mid == 0 && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            if (mid == n - 1 && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            // Normal check
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            if (mid % 2 == 1) {
                if (nums[mid] == nums[mid + 1]) {
                    high = mid - 1;
                } else if (nums[mid] == nums[mid - 1]) {
                    low = mid + 1;
                }
            } 
            else if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    low = mid + 1;
                } else if (nums[mid] == nums[mid - 1]) {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
