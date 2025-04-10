class Solution {
public:
    // Merge two sorted subarrays and update count of smaller elements after self
    void merge(vector<int>& smallerCounts, vector<pair<int, int>>& valueIndexPairs, int low, int mid, int high) {
        vector<pair<int, int>> merged;

        int left = low;
        int right = mid + 1;

        // Number of smaller elements on the right that have been merged before the current left element
        int smallerRightNumbers = 0;

        while (left <= mid && right <= high) {
            if (valueIndexPairs[left].first <= valueIndexPairs[right].first) {
                // All smaller right elements merged before this left element are counted
                smallerCounts[valueIndexPairs[left].second] += smallerRightNumbers;
                merged.push_back(valueIndexPairs[left]);
                left++;
            } else {
                // This right element is smaller than the current left element
                smallerRightNumbers++;
                merged.push_back(valueIndexPairs[right]);
                right++;
            }
        }

        // Remaining left half elements may still have smaller elements on right counted
        while (left <= mid) {
            smallerCounts[valueIndexPairs[left].second] += smallerRightNumbers;
            merged.push_back(valueIndexPairs[left]);
            left++;
        }

        // Push remaining right elements as-is
        while (right <= high) {
            merged.push_back(valueIndexPairs[right]);
            right++;
        }

        // Copy merged results back to the original vector
        for (int i = low; i <= high; i++) {
            valueIndexPairs[i] = merged[i - low];
        }
    }

    // Recursive merge sort that also updates the count of smaller elements
    void mergeSort(vector<int>& smallerCounts, vector<pair<int, int>>& valueIndexPairs, int low, int high) {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        // Sort and count for left and right halves
        mergeSort(smallerCounts, valueIndexPairs, low, mid);
        mergeSort(smallerCounts, valueIndexPairs, mid + 1, high);

        // Merge the halves and count cross-pairs
        merge(smallerCounts, valueIndexPairs, low, mid, high);
    }

    // Main function that returns the count of smaller numbers after self
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return {0};
        }

        // Pair each number with its original index
        vector<pair<int, int>> valueIndexPairs(n);
        for (int i = 0; i < n; i++) {
            valueIndexPairs[i] = {nums[i], i};
        }

        // Initialize result array to hold the counts
        vector<int> smallerCounts(n, 0);

        // Start the merge sort and count process
        mergeSort(smallerCounts, valueIndexPairs, 0, n - 1);

        return smallerCounts;
    }
};
