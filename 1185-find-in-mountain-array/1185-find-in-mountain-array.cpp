class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();

        /*
         Idk how LC marked this hard, its 3 BS back to back
         First BS to find the peak element
         Set low = 0, high = n-1 and narrow it down.
         After this, peakIndex stores the peak of the mountain.
         */
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }
        int peakIndex = low; // Yeah low

        /*
          BS on the increasing part (0 → peakIndex)
          Standard binary search. If mid == target, return it.
          Easy peasy.
         */
        low = 0;
        high = peakIndex;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        /*
          BS on the decreasing part (peakIndex → n-1)
          Btw, the array is flipped, so comparisons are reversed.
          If mid == target, return it.
         */
        low = peakIndex;
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val < target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1; // We didnt find it so here u go
    }
};
