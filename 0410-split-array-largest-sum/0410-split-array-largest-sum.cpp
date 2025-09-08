class Solution {
public:
    // This problem is literally the same as Allocate Minimum Pages
    bool valid(vector<int>& nums, int n, int maxSumAllowed, int maxSplits) {
        
        /* By default, we will always have at least 1 split 
        (the whole array if nothing else) */
        int splitCount = 1;
        
        // Keep track of the running sum of the current subarray
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            
            /* If the current element can be added without exceeding maxSumAllowed,
               then keep adding to the same subarray */
            if (sum + nums[i] <= maxSumAllowed) {
                sum += nums[i];
            } 
            else {
                /* If adding nums[i] exceeds maxSumAllowed, we need to 
                start a new split.
                So we increment splitCount and start a new subarray 
                beginning with nums[i]. */
                splitCount++;
                sum = nums[i];
                
                /* If at any point splitCount exceeds maxSplits, 
                that means it’s impossible to partition the array 
                within this maxSumAllowed */
                if (splitCount > maxSplits) {
                    return false;
                }
            }
        }
        
        // If we manage to split the array without exceeding maxSplits, it’s valid
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        // If we have fewer elements than the required number of splits, it's impossible
        if (n < k) {
            return -1;
        }

        /* Now understand this:
            If there’s at least one split (which there always is), 
            then the minimum sum any subarray can have is the largest element itself 
            (because that element has to go somewhere).
            So low = max element.
           
            On the other extreme, if k = 1, then the entire array is one partition,
            so high = sum of the whole array. */
        int low = 0;
        int high = 0;

        // Using one loop instead of two STL calls
        for (int i = 0; i < n; i++) {
            low = max(low, nums[i]);
            high += nums[i];
        }

        // Standard binary search
        while (low <= high) {
            int mid = low + (high - low) / 2;

            /* If it's valid with mid as the maxSumAllowed,
               then we might be able to minimize it further, so move left */
            if (valid(nums, n, mid, k)) {
                high = mid - 1;
            } 
            else {
                // Otherwise, move right since mid was too small
                low = mid + 1;
            }
        }

        // low points to the minimum possible maximum subarray sum
        return low;
    }
};
