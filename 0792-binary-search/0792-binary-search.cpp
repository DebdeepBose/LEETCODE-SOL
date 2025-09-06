class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        // Setting the initial ranges
        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            //Standard BS
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        //Imagine wasting O(logn) and getting nothing, couldn't be me
        return -1;
    }
};