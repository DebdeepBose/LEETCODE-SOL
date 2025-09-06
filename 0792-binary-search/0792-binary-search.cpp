class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        // Setting the initial ranges
        int low = 0;
        int high = n - 1;

        /*Yeah we doin low <= high insetad of low < high, cuz like if there's
        just 1 element then by default thats high so low is never 
        lesser then high, so loop doesn't start */
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