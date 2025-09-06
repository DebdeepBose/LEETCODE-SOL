class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        //Basic range initiation
        int low = 0;
        int high = n - 1;

        //Loop while low <= high
        while (low <= high) {
            int mid = low + (high - low) / 2;

            //Again Basic BS
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low; //I mean if u think about it low pointer always positions itself that way
    }
};