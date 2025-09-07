class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Edge case: if we got one element, return it
        if (n == 1) {
            return nums[0];
        }

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            /*Yeah so, if mid's 0 and the next one to mid aint equal to it then
             we can return nums[mid] cuz there is no one on its left to
             compare to */
            if (mid == 0 && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            /*Same game, if mid is n-1 aka the last element there is no one on
             its right to compare to so GG*/
            if (mid == n - 1 && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            /*Now this one, if mid is somewhere in the middle (no pun intended)
            then we check on its right and left side if nums[mid] sint equal to
            either of them, then we are pretty sure its the single element*/
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            /*The following if-else stuff had to be done like take/not_take in
             recursion, well not exactly similar but yeah you get the point*/

            if (mid % 2 == 1) {

                /*if mid's odd and nums[mid+1] is equal to nums[mid] that means,
                 the single element has to lie on its left so we get rid of
                 the right side*/
                if (nums[mid] == nums[mid + 1]) {
                    high = mid - 1;

                    /*if mid's odd and nums[mid-1] is equal to nums[mid] that
                     means, the single element has to lie on its right so we
                     get rid of the left side*/
                } else if (nums[mid] == nums[mid - 1]) {
                    low = mid + 1;
                }
            } else if (mid % 2 == 0) {

                /*if mid's even and nums[mid+1] is equal to nums[mid] that
                 means, the single element has to lie on its right so we get
                 rid of the left side*/
                if (nums[mid] == nums[mid + 1]) {
                    low = mid + 1;

                    /*if mid's even and nums[mid+1] is equal to nums[mid] that
                     means, the single element has to lie on its left so we
                     get rid of the right side*/
                } else if (nums[mid] == nums[mid - 1]) {
                    high = mid - 1;
                }
            }
        }
        // Idk why have i put this here, there's no case for it in leetcode.
        return -1;
    }
};
