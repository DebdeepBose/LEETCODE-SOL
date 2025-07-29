class Solution {
public:
    // Standard iterative binary search algorithm
    int binarySearch(vector<int>& v, int x, int low, int high) {
        while (low <= high) {
            // We are using <= and not <
            // to handle cases such as [2], target = 2
            // one number so low == high initially
            // if we use low < high, the while loop wouldn't even start
            int mid = low + (high - low) / 2;  // avoids overflow

            if (v[mid] == x) {
                return mid; // Element found at index mid
            } else if (v[mid] > x) {
                high = mid - 1; // Discard right half
            } else {
                low = mid + 1; // Discard left half
            }
        }
        return -1; // Element not found
    }

    // Wrapper function that initiates binary search
    int search(vector<int>& v, int x) {
        int n = v.size(); // Total elements in the vector
        return binarySearch(v, x, 0, n - 1);
    }
};
