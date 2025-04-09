class Solution {
public:
    // Function to merge two sorted subarrays and count reverse pairs
    int mergeAndCount(vector<int>& nums, int low, int mid, int high) {
        int reversePairCount = 0;
        int leftPtr = low;
        int rightPtr = mid + 1;

        // Count the reverse pairs (nums[i] > 2 * nums[j]) using two pointers
        while (leftPtr <= mid) {
            while (rightPtr <= high && (long long)nums[leftPtr] > 2LL * nums[rightPtr]) {
                rightPtr++;
            }
            reversePairCount += (rightPtr - (mid + 1)); // Add how many j's satisfy the condition for current i
            leftPtr++;
        }

        // Merge the two sorted halves
        vector<int> merged;
        int i = low, j = mid + 1;

        // Merge sort logic to combine two sorted subarrays
        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                merged.push_back(nums[i++]);
            } else {
                merged.push_back(nums[j++]);
            }
        }

        // Add remaining elements from left half (if any)
        while (i <= mid) {
            merged.push_back(nums[i++]);
        }

        // Add remaining elements from right half (if any)
        while (j <= high) {
            merged.push_back(nums[j++]);
        }

        // Copy the sorted merged array back into the original array
        for (int k = low; k <= high; k++) {
            nums[k] = merged[k - low];
        }

        return reversePairCount;
    }

    // Recursive merge sort function that returns reverse pair count
    int mergeSortAndCount(vector<int>& nums, int low, int high) {
        if (low >= high)
            return 0;

        int mid = (low + high) / 2;
        int count = 0;

        // Count in left half
        count += mergeSortAndCount(nums, low, mid);

        // Count in right half
        count += mergeSortAndCount(nums, mid + 1, high);

        // Count during merge
        count += mergeAndCount(nums, low, mid, high);

        return count;
    }

    // Main function to call mergeSort with reverse pair counting
    int reversePairs(vector<int>& nums) {
        return mergeSortAndCount(nums, 0, nums.size() - 1);
    }
};
