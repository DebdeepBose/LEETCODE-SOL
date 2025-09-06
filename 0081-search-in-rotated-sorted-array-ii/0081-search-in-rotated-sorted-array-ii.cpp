class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        //Pretty much the same code as Part-1
        
        // Basic initialization
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        if (n == 0) {
            return false;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Basic BS mid check
            if (nums[mid] == target) {
                return true;
            }

            /*The only edge case here is if nums[low]==nums[mid]==nums[high]
            and in that case we dunno if the right part is sorted or the left
            part so we reduce the search space by 1 from both sides*/
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            /*The reason we used if + continue and not while cuz, for a new
               search space there would be a new mid so we can't just go on with
               our previosu mid*/

          

            // Checking if left side is sorted or not
            else if (nums[low] <= nums[mid]) {

                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // Check da right side
            else {

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