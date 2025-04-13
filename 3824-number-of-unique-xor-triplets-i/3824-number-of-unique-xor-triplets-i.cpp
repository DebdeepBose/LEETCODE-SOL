class Solution {
public:
    // Function to estimate the number of unique XOR triplets that can be formed
    int uniqueXorTriplets(vector<int>& v) {
        int numOfOneRightShifts = 0;
        int size = v.size();

        // If array has less than 3 elements, return its size
        // Since the number of triplets (i, j, k) with i <= j <= k requires at least 3 elements
        if (size <= 2) {
            return size;
        }

        // Count how many times we can right shift 'size' before it becomes 0
        while (size > 0) {
            size >>= 1;                  // Equivalent to size = size / 2
            numOfOneRightShifts++;       // Count number of right shifts
        }

        // Return the upper bound of possible unique XOR values (2 ^ number of bits)
        return pow(2, numOfOneRightShifts);
    }
};
