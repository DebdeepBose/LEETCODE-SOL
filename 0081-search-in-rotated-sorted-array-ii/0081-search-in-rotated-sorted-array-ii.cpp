class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Basic initialization
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        if(n==0){
            return false;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Basic BS mid check
            if (nums[mid] == target) {
                return true;
            }
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            /*Now heres the thing, this array aint perfectly sorted
            so we gotta check whcih side of the mid is sorted,
            the moment we find the sorted side we check if our target exists
            in that sorted subarray or not, if it does, since its sorted
            we can use BS, if it doesn't well we eliminate it*/

            // Checking if left side is sorted or not
            else if (nums[low] <= nums[mid]) {

                /*Yeah we check >= for low and not for mid, cuz we already have
                 a check for mid in the first place, so nums[mid] cannot be
                 target*/
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // Check da right side
            else {

                // Same reason we check <= with high
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;

                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};