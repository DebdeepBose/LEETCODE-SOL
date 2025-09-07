class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        /*Yeah there's a lot of edge cases here
        firstly if array has 1 element, return 0*/
        if (n == 1) {
            return 0;
        }
        /*If it has 2 elements,then depeneding upon which one's greater, we
         return its index*/
        if (n == 2) {
            if (nums[0] > nums[1]) {
                return 0;
            } else if (nums[1] > nums[0]) {
                return 1;
            }
        }

        /*I think maybe i shud move these 2 edge cases on top but anyway, its
        clear as day if the first or last element is greater than its one-sided
        neighbour we could return them indices*/
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }
        if (nums[0] > nums[1]) {
            return 0;
        }

        /* Basic setup, but since we already took care of first and last element
         * we start low form 1 and high from n-2*/

        int low = 1;
        int high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            /* Now here this one's the main peak-checker, if we find a peak
            we return that index, pretty straightforward*/
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                return mid;
            }

            /*But then what if the mid element is greater than the previosu
               element but smaller than its next element, its kinda like a slope
               like this one --> / ascending slope */
            else if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }
            /*Here i could have explicitly stated the descending slope criteria
               but theres also another case like 0 1 0 1 0, the mid here is the
               opposite of peak, so we can just bundle it alongside descending
               slope for high = mid - 1 */
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
